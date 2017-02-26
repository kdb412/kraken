#include "parse.h"
#include "data_types.h"

uint8_t krk_get_column_type(uint8_t *s)
{
  if(!strncmp(s, "varchar", strlen("varchar")))
    return k_varch;

  if(!strncmp(s, "int", strlen("int")))
    return k_int;

  if(!strncmp(s, "b_int", strlen("b_int")))
    return k_bigint;

  if(!strncmp(s, "float", strlen("float")))
    return k_float;

  if(!strncmp(s, "bin", strlen("bin")))
    return k_bin;

  if(!strncmp(s, "bool", strlen("bool")))
    return k_bool;


  return 0;
}

