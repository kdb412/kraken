
#include "query_s.h"
#include "global_types.h"
#include <pthread.h>
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#endif

krk_query_s krk_qserv_inst;
extern k_byte KRK_SIGNAL;

int krk_startqueryservice()
{
    int tsock = 0;
    struct sockaddr_in saddr;
    pthread_t service_t;
    pthread_attr_t attr_t;

    memset(&saddr, 0, sizeof(struct sockaddr_in));
    memset(&krk_qserv_inst, 0, sizeof(krk_query_s));

    tsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(tsock < 0 )
        return 1;

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(50000);
    saddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(tsock, (struct sockaddr*) &saddr, sizeof(struct sockaddr)) < 0)
        return 1;

    if(listen(tsock, 40) < 0)
        return -1;

    krk_qserv_inst.list_sock = tsock;

    // create detached listening service
    pthread_attr_setdetachstate(&attr_t, PTHREAD_CREATE_DETACHED);
    pthread_create(&service_t, &attr_t, krk_queryservice, NULL);
    pthread_attr_destroy(&attr_t);

    return 0;
}

void* krk_queryservice(void *p)
{
    struct sockaddr_in client;
    int client_sock = 0;
    int client_sz = sizeof(struct sockaddr_in);

    fprintf(stdout, "query service started\n");

    while(!KRK_SIGNAL)
    {
        client_sock = accept(krk_qserv_inst.list_sock,
                             (struct sockaddr *)&client, &client_sz);
    }

}
