#pragma once

#include <inttypes.h>

typedef struct {
  uint32_t h0;
  uint32_t h1;
  uint32_t h2;
  uint32_t h3;
  uint32_t h4;
} DIGEST;

typedef struct {
  uint64_t size;
  uint64_t r_len;
  DIGEST hash;
} krk_sha;

void krk_nxtHash(krk_sha* ctx, char* data);
int32_t krk_initSHA(krk_sha** ctx, uint64_t size);
void krk_hashStr(krk_sha* ctx, char* hashstr);
