#include <dirent.h>
#include <stdio.h>
#include "engine.h"

const uint16_t krk_MAX_DB_PATH = 4096;

int krk_checkdbpath(char *p)
{
	DIR *_dbp = opendir(p);

	if(_dbp == NULL)
	{
		return 1;
	}
	closedir(_dbp);
	return 0;
}

int krk_engineinit(char *p, uint16_t sz)
{
	fprintf(stdout, "initializing database engine... ");

	if(sz > krk_MAX_DB_PATH)
	{
		fprintf(stderr, "\nfile path size @%s,[error]\n", p);
		return 1;
	}

	if(krk_checkdbpath(p))
	{
		fprintf(stderr, "\ndb path error @%s,[error]\n", p);
		return 1;
	}

	fprintf(stdout, "Done\n");
	fprintf(stderr, "using db path @%s\n", p);
	return 0;
}
