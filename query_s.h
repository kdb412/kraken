#pragma once

#include "global_types.h"
#include <inttypes.h>

typedef struct _query_s
{
    int list_sock;
} krk_query_s;

int krk_startqueryservice();
void * krk_queryservice(void *p);
void * krk_queryrequest_thread(void *p);
uint8_t krk_query_process(kn_block *nbl, int32_t *sock);