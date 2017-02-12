#include "krk_storage.h"

uint8_t krk_mountdb(uchar* c)
{

  pthread_mutex_lock(&(krk_dbpath.spl));
  if(krk_dbpath.mounted == 0) {
    if(!_krk_mountdb(c))
      krk_dbpath.mounted = 1;
  } else {
    pthread_mutex_unlock(&(krk_dbpath.spl));
    return 1;
  }
  pthread_mutex_unlock(&(krk_dbpath.spl));
  return (uint8_t)(krk_dbpath.mounted ? 0 : 1);
}
