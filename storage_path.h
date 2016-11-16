#pragma once

#include <inttypes.h>
#include <pthread.h>
#include <dirent.h>
#include "global_types.h"

typedef struct _krk_db_path
{
	char dbname[50];   // this is determined parsing dbpath
	char dbpath[4096];
	pthread_mutex_t spl;
	DIR *_dp;

} krk_db_path;

int krk_prepstoragepath(char *p, uint16_t sz);
int krk_checkdbpath(char *p);
void krk_unprepstoragepath();
