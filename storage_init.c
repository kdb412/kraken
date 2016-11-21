
#include "storage_init.h"
#include "storage_path.h"


extern krk_db_path krk_dbpath;
krk_databasemeta krk_db;

// forward declarations of internal function
uint8_t _krk_mountdb(uchar *c);

uint8_t _krk_umountdb(uchar *c);

uint8_t _krk_createdb(uchar *c);

uint8_t krk_mountdb(uchar *c) {

    pthread_mutex_lock(&(krk_dbpath.spl));
    if (krk_dbpath.mounted == 0) {

        if (!_krk_mountdb(c))
            krk_dbpath.mounted = 1;
    } else {
        pthread_mutex_unlock(&(krk_dbpath.spl));
        return 1;
    }
    pthread_mutex_unlock(&(krk_dbpath.spl));

    return (uint8_t) (krk_dbpath.mounted ? 0 : 1);
}

uint8_t krk_createdb(uchar *c) {
    uint8_t ret = 1;

    pthread_mutex_lock(&(krk_dbpath.spl));
    if (krk_dbpath.mounted == 0)
        ret = _krk_createdb(c);
    pthread_mutex_unlock(&(krk_dbpath.spl));

    return ret;
}

uint8_t krk_umountdb(uchar *c) {

    pthread_mutex_lock(&(krk_dbpath.spl));
    if (krk_dbpath.mounted == 1) {
        if (!_krk_umountdb(c))
            krk_dbpath.mounted = 0;
    } else {
        pthread_mutex_unlock(&(krk_dbpath.spl));
        return 1;
    }
    pthread_mutex_unlock(&(krk_dbpath.spl));

    return (uint8_t) (krk_dbpath.mounted ? 1 : 0);
}


uint8_t _krk_mountdb(uchar *c) {
	char krk_base[4096] = {0};
	if(krk_dbpath.mounted)
        return 1;

	// mount the database
	strcpy(krk_base, krk_dbpath.dbpath);
	strcat(krk_base, "/base.kr");
	krk_db.db_file = fopen(krk_base, "rb");
	if(!krk_db.db_file)
		return 1;

	// read the base.kr file

    return 0;
}

uint8_t _krk_umountdb(uchar *c) {
    return 0;
}

uint8_t _krk_createdb(uchar *c) {
    return 0;
}