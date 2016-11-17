
#include "storage_init.h"
#include "storage_path.h"

extern krk_db_path krk_dbpath;

uint8_t mountDatabase(uchar *c) {

	pthread_mutex_lock(&(krk_dbpath.spl));
	return 0;
}

uint8_t createDatabase(uchar *c) {
	return 0;
}

uint8_t unmountDatabase(uchar *c) {

	pthread_mutex_unlock(&(krk_dbpath.spl));
	return 0;
}
