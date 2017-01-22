#include "data_types.h"

kr_type_pair getType(krk_col_ty t, uint16_t len)
{
    kr_type_pair p = {0, 0};

    if (t == k_varch && len > 0 && len <= 65535)
    {
        p.type = t;
        p.sz = sizeof(k_varch) * len;
        p.t = malloc(p.sz);
    }
    else if (t == k_int)
    {
        p.type = t;
        p.sz = sizeof(k_int);
        p.t = malloc(p.sz);
    }
    else if (t == k_bigint)
    {
        p.type = t;
        p.sz = sizeof(k_int);
        p.t = malloc(p.sz);
    }
    else if (t == k_float)
    {
        p.type = t;
        p.t = malloc(sizeof(k_float));
    }
    else if (t == k_bin && len > 0 && len <= 65535)
    {
        p.type = t;
        p.sz = sizeof(k_int) * len;
        p.t = malloc(p.sz);
    }

    return p;
}

uint64_t getSize(krk_col_ty t, uint16_t len)
{
    uint64_t sz = 0;
    if (t == k_varch && len > 0 && len <= 65535)
    {
        sz = sizeof(k_varch) * len;
    }
    else if (t == k_int)
    {
        sz = sizeof(k_int) * len;
    }
    else if (t == k_bigint)
    {
        sz = sizeof(k_bigint) * len;
    }
    else if (t == k_float)
    {
        sz = sizeof(k_float) * len;
    }
    else if (t == k_bin && len > 0 && len <= 65535)
    {
        sz = sizeof(k_bin) * len;
    }
    return sz;
}