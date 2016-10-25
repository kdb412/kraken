#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "query_s.h"

const uint16_t krk_MAX_DB_PATH = 4096;
krk_db_engine krk_db_inst;

int krk_checkdbpath(char *p)
{
	DIR *_dbp = opendir(p);

	if(_dbp == NULL)
	{
		return 1;
	}

    // configure the instance object's path
    memset(&krk_db_inst, 0, sizeof(krk_db_engine));
	krk_db_inst._dp = _dbp;
    strncpy(krk_db_inst.dbpath, p, krk_MAX_DB_PATH);

    return 0;
}

int krk_engineinit(char *p, uint16_t sz)
{
	fprintf(stdout, "initializing database engine... ");

	if(sz > krk_MAX_DB_PATH)
	{
		fprintf(stdout, "\nfile path size @%s,[error]\n", p);
		return 1;
	}

	if(krk_checkdbpath(p))
	{
		fprintf(stdout, "\ndb path error @%s,[error]\n", p);
		return 1;
	}


	fprintf(stdout, "Done\n");
	fprintf(stdout, "using db path @%s\n", p);

    // start query service
    if(krk_startqueryservice())
    {
        fprintf(stdout, "attemp to start query service failed\n");
        return 1;
    }

	return 0;
}

void krk_enginestop()
{
    fprintf(stdout, "stopping  database engine... ");
    closedir(krk_db_inst._dp);
    memset(&krk_db_inst, 0, sizeof(krk_db_engine));
    fprintf(stdout, "done\n");
}