#include "q_processor.h"
#include "query_context.h"

#include <stdlib.h>

uint8_t q_processor(uchar *c,  uint8_t *item[200], uint16_t sz[200])
{


  // free up memory
  for(int i = 0; i < 200; i++)
    {
      if(item[i] == NULL)
	break;
      free(item[i]);
    }
  return 0;
}
