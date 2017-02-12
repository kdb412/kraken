#include "b64.h"

extern const unsigned char krk_b64[64];
int krk_b64dec(unsigned char** data, unsigned char* t_b64, int sz)
{
  int decSz = 0;
  int dat_cntr = 0;
  int b64_cntr = 0;
  int cntr = 0;
  unsigned char* b64_dataPtr = 0;
  unsigned char* dataPtr = 0;
  int suffixCnt = 0;
  int a = 0, b = 0, c = 0, d = 0;
  int suffixAdjuster = 0;

  suffixCnt = 0;
  cntr = sz;
  while(cntr > sz - 3) {
    if(t_b64[cntr - 1] == '=')
      suffixCnt++;
    cntr--;
  }

  suffixAdjuster = 0;
  suffixAdjuster += (suffixCnt != 0) ? 4 : 0;

  switch(suffixCnt) {
  case 2:
    decSz += 1;
    break;
  case 1:
    decSz += 2;
    break;
  }

  decSz += (((sz - suffixAdjuster) / 4) * 3);
  (*data) = (unsigned char*)calloc(sizeof(unsigned char), decSz + 3);
  dataPtr = *data;
  b64_dataPtr = t_b64;

  while(b64_cntr < sz - suffixAdjuster) {
    a = base64DecHelper(*b64_dataPtr);
    b = base64DecHelper(*(b64_dataPtr + 1));
    c = base64DecHelper(*(b64_dataPtr + 2));
    d = base64DecHelper(*(b64_dataPtr + 3));

    *dataPtr = (((a) << 2) & 0xfc) | (((b) >> 4) & 0x03);
    *(dataPtr + 1) = (((b) << 4) & 0xf0) | (((c) >> 2) & 0x0f);
    *(dataPtr + 2) = (((c) << 6) & 0xc0) | (((d)) & 0x3f);
    dataPtr += 3;
    dat_cntr += 3;
    b64_dataPtr += 4;
    b64_cntr += 4;
  }

  switch(suffixCnt) {
  case 2:
    a = base64DecHelper(*b64_dataPtr);
    b = base64DecHelper(*(b64_dataPtr + 1));
    *dataPtr = (((a) << 2) & 0xfc) | (((b) >> 4) & 0x03);
    break;
  case 1:
    a = base64DecHelper(*b64_dataPtr);
    b = base64DecHelper(*(b64_dataPtr + 1));
    c = base64DecHelper(*(b64_dataPtr + 2));
    *dataPtr = (((a) << 2) & 0xfc) | (((b) >> 4) & 0x03);
    *(dataPtr + 1) = (((b) << 4) & 0xf0) | (((c) >> 2) & 0x0f);
    break;
  }

  return decSz;
}
