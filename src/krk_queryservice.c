#include "query_s.h"

void *krk_queryservice(void *p)
{
  pthread_t serv;
  pthread_attr_t attr_t;
  struct sockaddr_in client;
  int client_sock = 0;
  int *clsock = NULL;
  int client_sz = sizeof(struct sockaddr_in);

  fprintf(stdout, "query service started\n");

  while (!KRK_SIGNAL)
  {
    client_sock = accept(krk_qserv_inst.list_sock,
                         (struct sockaddr *)&client, &client_sz);

    if (client_sock == -1)
    {
      usleep(10000);
      continue;
    }

    clsock = (int *)malloc(sizeof(int));
    *clsock = client_sock;
    pthread_attr_init(&attr_t);
    pthread_attr_setdetachstate(&attr_t, PTHREAD_CREATE_DETACHED);
    pthread_create(&serv, &attr_t, krk_queryrequest_thread, clsock);
    pthread_attr_destroy(&attr_t);
    client_sock = 0;
  }
}
