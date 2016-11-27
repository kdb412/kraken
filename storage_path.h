#pragma once

#include <inttypes.h>
#include <pthread.h>
#include <dirent.h>
#include "global_types.h"

typedef struct _krk_db_path
{
	char dbpath[4096];
	uint8_t mounted;
	pthread_mutex_t spl;
} krk_db_path;

int krk_checkstoragepath(char *p, uint16_t sz);
int _krk_checkdbpath(char *p);

