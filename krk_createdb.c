#include "krk_storage.h"

uint8_t krk_createdb(uchar *c)
{
  uint8_t ret = 1;

  pthread_mutex_lock(&(krk_dbpath.spl));
  if (krk_dbpath.mounted == 0)
    ret = _krk_createdb(c);
  pthread_mutex_unlock(&(krk_dbpath.spl));

  return ret;
}
