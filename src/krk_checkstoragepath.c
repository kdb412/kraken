#include "storage_path.h"
#include <stdio.h>

int krk_checkstoragepath(char *p, uint16_t sz)
{
  fprintf(stdout, "preparing storage path... ");

  if (sz > krk_MAX_DB_PATH)
  {
    fprintf(stderr, "\nfile path size @%s,[error]\n", p);
    return 1;
  }

  if (_krk_checkdbpath(p))
  {
    fprintf(stderr, "\ndb path error @%s,[error]\n", p);
    return 1;
  }

  fprintf(stdout, "done\n");
  fprintf(stdout, "using db path @%s\n", p);

  // start query service
  if (krk_startqueryservice())
  {
    fprintf(stderr, "attempt to start query service failed\n");
    return 1;
  }

  return 0;
}
