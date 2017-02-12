#include "query_s.h"

void* krk_queryrequest_thread(void* p)
{
  const static uint8_t BSZ = 4096;
  int32_t* clsock = p;
  uint16_t req_t = 0;
  uint16_t req_s = 0;
  int16_t req_r = 0;
  uint8_t req_start = 1;
  kn_block* nblock = malloc(sizeof(kn_block));

  for(;;) {
    if(req_s == 0)
      req_r = recv(*clsock, nblock, BSZ, 0);
    else
      req_r = recv(*clsock, &nblock[req_s - req_t], req_s - req_t, 0);

    if(req_r > 0) {
      req_t += req_r;

      if(req_t == req_s) {
        if(krk_query_process(nblock, clsock))
          break;

        // reset counters after processing
        req_t = 0;
        req_s = 0;
        req_r = 0;
        req_start = 1;
      } else if(req_start == 1 && req_t > sizeof(uint8_t)) {
        memcpy(&req_s, nblock, sizeof(uint8_t));
        req_start = 0;
      }
    } else if(req_r < 0) // socket closed
    {
      break;
    } else {
      usleep(10000);
      continue;
    }
  }

  close(*clsock);
  free(clsock);
  free(nblock);
}