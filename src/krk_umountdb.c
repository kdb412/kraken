#include "krk_storage.h"

uint8_t krk_umountdb(uchar* c)
{

  pthread_mutex_lock(&(krk_dbpath.spl));
  if(krk_dbpath.mounted == 1) {
    if(!_krk_umountdb(c))
      krk_dbpath.mounted = 0;
    memset(&krk_dbpath, 0, sizeof(krk_db_path));
  } else {
    pthread_mutex_unlock(&(krk_dbpath.spl));
    return 1;
  }
  pthread_mutex_unlock(&(krk_dbpath.spl));

  return (uint8_t)(krk_dbpath.mounted ? 1 : 0);
}
