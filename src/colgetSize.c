#include "data_types.h"

uint64_t colgetSize(krk_col_ty t, uint16_t len)
{
  uint64_t sz = 0;
  if(t == k_varch && len > 0 && len <= 65535) {
    sz = sizeof(k_varch) * len;
  } else if(t == k_int) {
    sz = sizeof(k_int) * len;
  } else if(t == k_bigint) {
    sz = sizeof(k_bigint) * len;
  } else if(t == k_float) {
    sz = sizeof(k_float) * len;
  } else if(t == k_bin && len > 0 && len <= 65535) {
    sz = sizeof(k_bin) * len;
  }
  return sz;
}