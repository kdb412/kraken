#include "query_s.h"

int krk_startqueryservice()
{
  int tsock = 0;
  struct sockaddr_in saddr;
  pthread_t service_t;
  pthread_attr_t attr_t;
  uint16_t port_range = 49999;

  memset(&saddr, 0, sizeof(saddr));
  memset(&krk_qserv_inst, 0, sizeof(krk_query_s));

#ifdef _WIN32
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

  tsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if(tsock < 0)
    return 1;

  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = inet_addr("0.0.0.0");

UPDATE_PORT_RANGE:
  port_range++;
  saddr.sin_port = htons(port_range);

  if(port_range > 50010)
    return -1;

  if(bind(tsock, (struct sockaddr*)&saddr, sizeof(saddr)) == -1 &&
      port_range < 50010) {
    goto UPDATE_PORT_RANGE;
  }

  if(listen(tsock, 40) < 0)
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

  fprintf(stdout, "listening on port: %d\n", port_range);

  // create detached listening service
  pthread_attr_init(&attr_t);
  pthread_attr_setdetachstate(&attr_t, PTHREAD_CREATE_DETACHED);
  pthread_create(&service_t, &attr_t, krk_queryservice, NULL);
  pthread_attr_destroy(&attr_t);

  return 0;
}
