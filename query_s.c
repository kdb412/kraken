
#include "query_s.h"
#include <pthread.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#endif

krk_query_s krk_qserv_inst;

int krk_startqueryservice()
{
    int tsock = 0;
    struct sockaddr_in saddr;

    memset(&saddr, 0, sizeof(struct sockaddr_in));
    memset(&krk_qserv_inst, 0, sizeof(krk_query_s));

    tsock = socket(AF_INET, SOCK_STREAM, 0);
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
    return 0;
}
