#include <stdio.h>
#include <string.h>
#include "storage_path.h"
#include "query_s.h"

const uint16_t krk_MAX_DB_PATH = 4096;
krk_db_path krk_dbpath;

int krk_checkdbpath(char *p) {
	DIR *_dbp = opendir(p);

	if (_dbp == NULL) {
		return 1;
	}

	// configure the instance object's path
	memset(&krk_dbpath, 0, sizeof(krk_db_path));
	//closedir(_dbp);
	strncpy(krk_dbpath.dbpath, p, krk_MAX_DB_PATH);

	return 0;
}

int krk_prepstoragepath(char *p, uint16_t sz) {
	fprintf(stdout, "preparing storage path... ");

	if (sz > krk_MAX_DB_PATH) {
		fprintf(stdout, "\nfile path size @%s,[error]\n", p);
		return 1;
	}

	if (krk_checkdbpath(p)) {
		fprintf(stdout, "\ndb path error @%s,[error]\n", p);
		return 1;
	}


	fprintf(stdout, "done\n");
	fprintf(stdout, "using db path @%s\n", p);

	// start query service
	if (krk_startqueryservice()) {
		fprintf(stdout, "attemp to start query service failed\n");
		return 1;
	}

	return 0;
}

void krk_unprepstoragepath() {
	fprintf(stdout, "releasing storage path reference... ");

	while(krk_dbpath.mounted) {}
	if (krk_dbpath._dp != NULL)
	{
		pthread_mutex_lock(&(krk_dbpath.spl));
		closedir(krk_dbpath._dp);
		pthread_mutex_unlock(&(krk_dbpath.spl));
	}
	memset(&krk_dbpath, 0, sizeof(krk_db_path));
	fprintf(stdout, "done\n");
}

