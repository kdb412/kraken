#pragma once

#include "query_s.h"
#include "query_context.h"
#include "global_types.h"
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

#include <inttypes.h>

typedef struct _query_s {
  int list_sock;
} krk_query_s;

krk_query_s krk_qserv_inst;
extern k_byte KRK_SIGNAL;

int krk_startqueryservice();
void* krk_queryservice(void* p);
void* krk_queryrequest_thread(void* p);
uint8_t krk_query_process(kn_block* nbl, int32_t* sock);
