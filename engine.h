#pragma once

#include <inttypes.h>
#include <pthread.h>

typedef struct _krk_db_engine
{
	char dbname[50];
	char dbpath[4096];
	pthread_mutex_t spl;
} krk_db_engine;

int krk_engineinit(char *p, uint16_t sz);
int krk_checkdbpath(char *p);
