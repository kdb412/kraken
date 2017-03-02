#include "krk_storage.h"
#include "parse.h"

uint8_t _krk_createtb(uchar *c)
{
  uint8_t ret = 1;
  if (!krk_dbpath.mounted)
  {
    goto end_request;
  }

  krk_sql_token *tk = krk_get_sql_token(c);
  if (!tk)
    goto end_request;

// create the table


end_request:
  return ret;
}
