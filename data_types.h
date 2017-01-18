#pragma once
#include "global_types.h"
#include <inttypes.h>

typedef enum _coltypes {
    k_varch = 900,
    k_int,
    k_bigint,
    k_float,
    k_bin
} krk_col_ty;

typedef uchar kr_varch;
typedef uint32_t kr_int;
typedef uint64_t kr_bigint;
typedef double kr_float;
typedef uchar kr_bin;

typedef struct _type_pair
{
    int type;
    uint16_t sz;
    void *t
} kr_type_pair;

// len is only used for bin and varchar types
// it is otherwise ignored
kr_type_pair getType(uint16_t t, uint16_t len);

// len is only used for bin and varchar types
// it is otherwise ignored
uint64_t getSize(uint16_t t, uint16_t len);
