#include "query_s.h"

// process request
uint8_t krk_query_process(kn_block* nbl, int32_t* sock)
{
  uint16_t req_s = 0;
  uint8_t user[9] = { 0 };
  uint8_t context[9] = { 0 };
  static uint16_t dataoffset = sizeof(uint16_t) + 8;

  // get size of request
  memcpy(&req_s, nbl, sizeof(uint16_t));

  // get user
  memcpy(&user, &nbl[sizeof(uint16_t)], 8);

  // TODO:  decrypt data
  // decryptData(uint8_t *user, kn_block *nbl);

  // get context
  memcpy(context, &nbl[dataoffset], 8);

  return krk_context_parse(
      sock, user, context, &nbl[dataoffset + 8], req_s - dataoffset - 8);
}
