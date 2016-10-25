#pragma once

typedef struct _query_s
{
    int list_sock;
} krk_query_s;

int krk_startqueryservice();
void * krk_queryservice(void *p);