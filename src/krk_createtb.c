#include "krk_storage.h"

uint8_t krk_createtb(uchar *c)
{
  uint8_t ret = 1;
  pthread_mutex_lock(&(krk_dbpath.spl));
  if (krk_dbpath.mounted == 1)
  {
    ret = _krk_createtb(c);
  }
  else
  {
    pthread_mutex_unlock(&(krk_dbpath.spl));
    return ret;
  }
  pthread_mutex_unlock(&(krk_dbpath.spl));

  return ret;
}
