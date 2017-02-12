#include "data_types.h"

kr_type_pair colgetType(krk_col_ty t, uint16_t len)
{
  kr_type_pair p = { 0, 0, 0 };

  if(t == k_varch && len > 0 && len <= 65535) {
    p.type = t;
    p.sz = sizeof(kr_varch) * len;
    p.t = malloc(p.sz);
  } else if(t == k_int) {
    p.type = t;
    p.sz = sizeof(kr_int);
    p.t = malloc(p.sz);
  } else if(t == k_bigint) {
    p.type = t;
    p.sz = sizeof(kr_bigint);
    p.t = malloc(p.sz);
  } else if(t == k_float) {
    p.type = t;
    p.sz = sizeof(kr_float);
    p.t = malloc(sizeof(kr_float));
  } else if(t == k_bool) {
    p.type = t;
    p.sz = sizeof(k_bool);
  } else if(t == k_bin && len > 0 && len <= 65535) {
    p.type = t;
    p.sz = sizeof(kr_int) * len;
    p.t = malloc(p.sz);
  }

  return p;
}
