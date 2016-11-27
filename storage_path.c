#include <stdio.h>
#include <string.h>
#include "storage_path.h"
#include "query_s.h"

const uint16_t krk_MAX_DB_PATH = 4096;
krk_db_path krk_dbpath;

int _krk_checkdbpath(char *p) {
    DIR *_dbp = opendir(p);

    if (_dbp == NULL) {
        return 1;
    }
    closedir(_dbp);

    // configure the instance object's path
    memset(&krk_dbpath, 0, sizeof(krk_db_path));
    strncpy(krk_dbpath.dbpath, p, krk_MAX_DB_PATH);

    return 0;
}

int krk_checkstoragepath(char *p, uint16_t sz) {
    fprintf(stdout, "preparing storage path... ");

    if (sz > krk_MAX_DB_PATH) {
        fprintf(stderr, "\nfile path size @%s,[error]\n", p);
        return 1;
    }

    if (_krk_checkdbpath(p)) {
        fprintf(stderr, "\ndb path error @%s,[error]\n", p);
        return 1;
    }


    fprintf(stdout, "done\n");
    fprintf(stdout, "using db path @%s\n", p);

    // start query service
    if (krk_startqueryservice()) {
        fprintf(stderr, "attempt to start query service failed\n");
        return 1;
    }

    return 0;
}


