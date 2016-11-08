
#include "query_s.h"
#include "global_types.h"
#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32

#include <windows.h>
#include <fcntl.h>
#include <unistd.h>

#else
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

#endif

krk_query_s krk_qserv_inst;
extern k_byte KRK_SIGNAL;

int krk_startqueryservice() {
    int tsock = 0;
    struct sockaddr_in saddr;
    pthread_t service_t;
    pthread_attr_t attr_t;

    memset(&saddr, 0, sizeof(saddr));
    memset(&krk_qserv_inst, 0, sizeof(krk_query_s));

#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    tsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tsock < 0)
        return 1;

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    saddr.sin_port = htons(50000);

    if (bind(tsock, (struct sockaddr *) &saddr, sizeof(saddr)) == -1)
        return 1;

    if (listen(tsock, 40) < 0)
        return -1;

#ifndef _WIN32
    int reuse = 1;
    fcntl(tsock, F_SETFL, O_NONBLOCK);
    setsockopt(tsock, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse));
#else
    u_long nonblockmode = 1;
    ioctlsocket(tsock, FIONBIO, &nonblockmode);
#endif

    krk_qserv_inst.list_sock = tsock;

    // create detached listening service
    pthread_attr_init(&attr_t);
    pthread_attr_setdetachstate(&attr_t, PTHREAD_CREATE_DETACHED);
    pthread_create(&service_t, &attr_t, krk_queryservice, NULL);
    pthread_attr_destroy(&attr_t);

    return 0;
}

void *krk_queryservice(void *p) {
    pthread_t serv;
    pthread_attr_t attr_t;
    struct sockaddr_in client;
    int client_sock = 0;
    int *clsock = NULL;
    int client_sz = sizeof(struct sockaddr_in);

    fprintf(stdout, "query service started\n");

    while (!KRK_SIGNAL) {
        client_sock = accept(krk_qserv_inst.list_sock,
                             (struct sockaddr *) &client, &client_sz);

        if (client_sock == -1) {
            usleep(10000);
            continue;
        }

        clsock = (int *) malloc(sizeof(int));
        *clsock = client_sock;
        pthread_attr_init(&attr_t);
        pthread_attr_setdetachstate(&attr_t, PTHREAD_CREATE_DETACHED);
        pthread_create(&serv, &attr_t, krk_queryproc, clsock);
        pthread_attr_destroy(&attr_t);
        client_sock = 0;
    }

}


void *krk_queryproc(void *p) {
    const static uint8_t BSZ = 4096;
    int *clsock = p;
    uint32_t req_t = 0;
    uint8_t req_s = 0;
    int32_t req_r = 0;
    kn_block *nblock = malloc(sizeof(kn_block));

    for(;;)
    {
        if (req_s == 0)
            req_r = recv(*clsock, nblock, BSZ, 0);
        else
            req_r = recv(*clsock, &nblock[req_s-req_t], req_s - req_t, 0);

        if(req_r > 0 )
        {
            req_t += req_r;

            if(req_t == req_s)
            {
                // TODO: process request


                // reset counters after processing
                req_t = 0;
                req_s = 0;
                req_r = 0;
            }

        }
        else
        {
            usleep(10000);
            continue;
        }
    }

    close(*clsock);
    free(clsock);
    free(nblock);
}
