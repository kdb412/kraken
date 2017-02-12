
#include "sha1.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static uint32_t h0 = 0x67452301;
static uint32_t h1 = 0xEFCDAB89;
static uint32_t h2 = 0x98BADCFE;
static uint32_t h3 = 0x10325476;
static uint32_t h4 = 0xC3D2E1F0;

static const int32_t END_TST = 0x01;
#define L_ENDIAN() ((*(char*)&END_TST) == 1)
#define LRT(x, y) (((x) << (y)) ^ ((x) >> (32 - y)))
#define REVBYTE32(w)                                                 \
  {                                                                  \
    uint32_t tmp = (w);                                              \
    tmp = (tmp >> 16) | (tmp << 16);                                 \
    (w) = ((tmp & 0xff00ff00UL) >> 8) | ((tmp & 0x00ff00ffUL) << 8); \
  }

int32_t krk_initSHA(krk_sha** ctx, uint64_t size)
{

  (*ctx) = (krk_sha*)malloc(sizeof(krk_sha));
  if((*ctx) == NULL)
    return -1;

  (*ctx)->hash.h0 = h0;
  (*ctx)->hash.h1 = h1;
  (*ctx)->hash.h2 = h2;
  (*ctx)->hash.h3 = h3;
  (*ctx)->hash.h4 = h4;
  (*ctx)->r_len = 0;

  (*ctx)->size = size;

  return 0;
}

void krk_nxtHash(krk_sha* ctx, char* data)
{
  uint32_t modSize = 0;
  char* tdata = 0;
  char* tdata_head = 0;
  uint64_t sizeInBits = 0;
  uint16_t wCtr = 0;
  uint16_t mainCtr = 0;
  uint32_t W[80];
  uint32_t K = 0x0;
  uint32_t temp = 0x0;
  uint32_t a, b, c, d, e, f;
  short twoBlockFlag = 0;

  if(ctx->size == 0)
    goto LAST;

  // hash already completed
  if(ctx->r_len == ctx->size)
    return;

  // determine if last block is being read
  if(ctx->r_len + 64 < ctx->size) {
    ctx->r_len += 64;
  } else if((ctx->r_len + 64) > ctx->size) {
    modSize = ((ctx->size) % 64);
    ctx->r_len += modSize;
  } else if((ctx->r_len + 64) == ctx->size) {
    modSize = -1;
    ctx->r_len += 64;
  }

  /*
   *file larger than 64bit length when
   *multiplied by 8 bits to get length in bits
   */

  if(ctx->size > 0xFFFFFFFFFFFFFFFFULL / 0x08) {
    ctx->size = (0xFFFFFFFFFFFFFFFFULL / 0x08);
  }

  sizeInBits = (uint64_t)((ctx->size) * 8);

  // preprocess now
  // last data block being read
  if(modSize) {
  LAST:
    (modSize < 56 && modSize != -1) ?
        (tdata = (char*)calloc(sizeof(char), 64)) :
        (tdata = (char*)calloc(sizeof(char), 128));

    (modSize == -1) ? memcpy(tdata, data, 64) : memcpy(tdata, data, modSize);

    // append 1 to message block
    (modSize == -1) ? (tdata[64] ^= 0x80) : (tdata[modSize] ^= 0x80);
    // flag if multi block for last block
    ((modSize == -1) || (modSize >= 56)) ? (twoBlockFlag = 1) :
                                           (twoBlockFlag = 0);
  } else {
    tdata = (char*)calloc(sizeof(char), 64);
    memcpy(tdata, data, 64);
  }

  tdata_head = &(tdata[0]);

CHK_AGAIN:

  a = ctx->hash.h0;
  b = ctx->hash.h1;
  c = ctx->hash.h2;
  d = ctx->hash.h3;
  e = ctx->hash.h4;

  memset(&W, 0, sizeof(int32_t) * 80);
  while(wCtr < 15) {
    wCtr == 0 ? memcpy(&W[wCtr], &tdata[wCtr], sizeof(int32_t)) :
                memcpy(&W[wCtr], &tdata[(wCtr * 4)], sizeof(int32_t));

    if((wCtr != 14)) {
      if(L_ENDIAN())
        REVBYTE32(W[wCtr]);
    } else {
      // if its the last block append the size in bits
      if(modSize && !twoBlockFlag) {
        if(L_ENDIAN()) {
          memcpy(&W[wCtr], &sizeInBits, 8);
          memcpy(&W[wCtr + 2], &W[wCtr + 1], 4); // swap
          memcpy(&W[wCtr + 1], &W[wCtr], 4);
          memcpy(&W[wCtr], &W[wCtr + 2], 4);
          memset(&W[wCtr + 2], 0, 4);
        } else {
          memcpy(&W[wCtr], &sizeInBits, 8);
        }
      } else {
        memcpy(&W[wCtr], &tdata[(wCtr * 4)], sizeof(int32_t));
        memcpy(&W[wCtr + 1], &tdata[((wCtr + 1) * 4)], sizeof(int32_t));
        if(L_ENDIAN()) {
          REVBYTE32(W[wCtr]);
          REVBYTE32(W[wCtr + 1]);
        }
      }
    }
    wCtr++;
  }

  wCtr++;

  while(wCtr < 80) {
    W[wCtr] = LRT((W[wCtr - 3] ^ W[wCtr - 8] ^ W[wCtr - 14] ^ W[wCtr - 16]), 1);
    wCtr++;
  }

  // main loop
  while(mainCtr < 80) {
    if(mainCtr <= 19) {
      K = 0x5A827999;
      f = (b & c) | ((~b) & d);
    } else if(20 <= mainCtr && mainCtr <= 39) {
      K = 0x6ED9EBA1;
      f = ((b) ^ (c)) ^ (d);
    } else if(40 <= mainCtr && mainCtr <= 59) {
      K = 0x8F1BBCDC;
      f = ((b & c) | (b & d)) | (c & d);
    } else if(60 <= mainCtr && mainCtr <= 79) {
      K = 0xCA62C1D6;
      f = ((b) ^ (c)) ^ (d);
    }
    temp = (LRT(a, 5) + f + e + K + W[mainCtr]);
    e = d;
    d = c;
    c = LRT(b, 30);
    b = a;
    a = temp;

    mainCtr++;
  }

  // main loop ends---------------
  ctx->hash.h0 += a;
  ctx->hash.h1 += b;
  ctx->hash.h2 += c;
  ctx->hash.h3 += d;
  ctx->hash.h4 += e;

  if(twoBlockFlag) {
    twoBlockFlag = 0;
    wCtr = 0;
    mainCtr = 0;
    tdata = &tdata[64];
    goto CHK_AGAIN;
  }

  free(tdata_head);
}

void krk_hashStr(krk_sha* ctx, char* hashstr)
{
  sprintf(&hashstr[0], "%08x", ctx->hash.h0);
  sprintf(&hashstr[8], "%08x", ctx->hash.h1);
  sprintf(&hashstr[16], "%08x", ctx->hash.h2);
  sprintf(&hashstr[24], "%08x", ctx->hash.h3);
  sprintf(&hashstr[32], "%08x", ctx->hash.h4);
}
