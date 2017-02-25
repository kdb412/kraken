#include "krk_storage.h"
#include "parse.h"

uint8_t _krk_createtb(uchar* c)
{
  uint8_t ret = 1;
  pthread_mutex_lock(&(krk_dbpath.spl));
  if(!krk_dbpath.mounted) {
    goto end_request;
  }

  krk_sql_token* tk = krk_get_sql_token(c);
  if(!tk)
    goto end_request;

end_request:
  pthread_mutex_unlock(&(krk_dbpath.spl));
  return ret;
}
