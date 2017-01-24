#include "krk_storage.h"

uint8_t _krk_createtb(uchar *c)
{
  pthread_mutex_lock(&(krk_dbpath.spl));
  if (!krk_dbpath.mounted)
  {
    pthread_mutex_unlock(&(krk_dbpath.spl));
    return 1;
  }


  pthread_mutex_unlock(&(krk_dbpath.spl));
  return 0;
}
