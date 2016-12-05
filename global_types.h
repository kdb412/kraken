#pragma once

#include <inttypes.h>

typedef char k_byte;
typedef unsigned char uchar;
typedef uchar kn_block[4096];
#define str(x) #x
static const uint64_t k_sep = 0xb00b1ee5;

typedef enum _coltypes
{
  k_varch = 900,
  k_int,
  k_bigint,
  k_float,
  k_bin
} krk_col_ty;
