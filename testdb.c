#include "testdb.h"
#include "krk_storage.h"
#include "system_a.h"

void runDBTests()
{
#ifdef TESTDB
  sleep(2);
  fprintf(stdout, "\n========================\n");

  fprintf(stdout, "Test create db: ");
  if (!krk_createdb("testdb"))
    fprintf(stdout, "1\n");
  else
    fprintf(stdout, "0\n");

  fprintf(stdout, "Test mount db: ");
  if (!krk_mountdb("testdb"))
    fprintf(stdout, "1\n");
  else
    fprintf(stdout, "0\n");

  fprintf(stdout, "Test add user: ");
  if (!krk_create_user("testuser", "pass"))
    fprintf(stdout, "1\n");
  else
    fprintf(stdout, "0\n");

  /*
  fprintf(stdout, "Test create table: ");
  if (!krk_create_user("testuser", "pass"))
    fprintf(stdout, "1\n");
  else
    fprintf(stdout, "0\n");
    */

  fprintf(stdout, "Test unmount db: ");
  if (!krk_umountdb("testdb"))
    fprintf(stdout, "1\n");
  else
    fprintf(stdout, "0\n");

  fprintf(stdout, "========================\n");
#endif
}
