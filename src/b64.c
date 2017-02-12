
#include "b64.h"
#include <stdlib.h>

const unsigned char krk_b64[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
  '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };

int base64DecHelper(unsigned char byte)
{
  int cntr = 0;
  while(cntr < 64) {
    if(krk_b64[cntr] == byte)
      return cntr;
    cntr++;
  }
  return 0;
}
