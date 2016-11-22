#pragma once

#include "global_types.h"

typedef struct _speck_ctx {
    uint64_t _k[4];
}speck_c;

static uint32_t _n = 64;
static uint32_t _m = 4;
static uint32_t _T = 34;
static uint64_t _z[2][5] = {
        0x32895873, 0x7d12b0e6,
        0x23be4c2d, 0x477c985a,
        0x2bdc0d26, 0x2847e5b3,
        0x36eb1978, 0x1229cd0f,
        0x3479ad88, 0x170ca4ef
};

int speck_init(speck_c *c, char *k, uint8_t sz);
void speck_enc(speck_c *c, char *d, uint8_t sz);
void speck_dec(speck_c *c, char *d, uint8_t sz);