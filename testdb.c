#include "testdb.h"

void runTests()
{
#ifdef TESTDB

  fprintf(stdout, "Test db create: ");
  if(!testDbCreate())
    fprintf(stdout, "0\n");
  else
    frpintf(stdout, "1\n");
  
#endif
}

uint8_t testDbCreate()
{

  return 0;
}
