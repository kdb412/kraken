#include "b64.h"

extern const unsigned char krk_b64[64];
int krk_b64enc(unsigned char* data, unsigned char** t_b64, int sz)
{
  int b64Size = 0;
  int dat_cntr = 0;
  int b64_cntr = 0;
  unsigned char* dataPtr = 0;
  int suffixCnt = 0;

  b64Size = (sz / 3) * 4;
  b64Size += ((sz % 3) != 0) ? 4 : 0;

  suffixCnt = 0;

  switch(sz % 3) {
  case 2:
    suffixCnt = 1;
    break;
  case 1:
    suffixCnt = 2;
    break;
  default:
    break;
  }

  (*t_b64) = (unsigned char*)calloc(sizeof(char), b64Size + 3);
  dataPtr = data;

  while(dat_cntr < sz) {
    if((dat_cntr == (sz - 1)) || (dat_cntr == (sz - 2))) {
      switch(suffixCnt) {
      case 1:
        (*t_b64)[b64_cntr + 0] = krk_b64[(*dataPtr) >> 2];
        (*t_b64)[b64_cntr + 1] = krk_b64[(((*dataPtr) & 0x03) << 4) |
            (((*(dataPtr + 1)) & 0xf0) >> 4)];
        (*t_b64)[b64_cntr + 2] = krk_b64[(((*(dataPtr + 1)) & 0x0f) << 2) |
            (((*(dataPtr + 2)) & 0xc0) >> 6)];
        dat_cntr = sz;
        break;
      case 2:
        (*t_b64)[b64_cntr + 0] = krk_b64[(*dataPtr) >> 2];
        (*t_b64)[b64_cntr + 1] = krk_b64[(((*dataPtr) & 0x03) << 4) |
            (((*(dataPtr + 1)) & 0xf0) >> 4)];
        dat_cntr = sz;
        break;
      case 0:
        break;
      default:
        break;
      }
    } else {
      (*t_b64)[b64_cntr + 0] = krk_b64[(*dataPtr) >> 2];
      (*t_b64)[b64_cntr + 1] = krk_b64[(((*dataPtr) & 0x03) << 4) |
          (((*(dataPtr + 1)) & 0xf0) >> 4)];
      (*t_b64)[b64_cntr + 2] = krk_b64[(((*(dataPtr + 1)) & 0x0f) << 2) |
          (((*(dataPtr + 2)) & 0xc0) >> 6)];
      (*t_b64)[b64_cntr + 3] = krk_b64[(*(dataPtr + 2)) & 0x3f];

      dataPtr += 3;
      b64_cntr += 4;
      dat_cntr += 3;
    }
  }

  if(suffixCnt == 1)
    (*t_b64)[b64Size - 1] = '=';
  if(suffixCnt == 2) {
    (*t_b64)[b64Size - 2] = '=';
    (*t_b64)[b64Size - 1] = '=';
  }

  return b64Size;
}
