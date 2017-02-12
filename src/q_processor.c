#include "q_processor.h"
#include "query_context.h"
#include "parse.h"

#include <stdlib.h>

uint8_t
q_processor(uint32_t* sock, uchar* c, uint8_t* item[200], uint16_t sz[200])
{

  // sql queries will be single items
  if(strcmp(c, "k_query") && item[0] != NULL) {
    // get query token
    krk_sql_token* qtk = krk_get_sql_token(item[0]);

    if(!qtk)
      goto free_out;
  }

// free up memory
free_out:
  for(int i = 0; i < 200; i++) {
    if(item[i] == NULL)
      break;
    free(item[i]);
    item[i] = NULL;
  }
  return 0;
}
