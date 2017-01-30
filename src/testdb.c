#include "testdb.h"
#include "krk_storage.h"
#include "krk_user.h"

void runDBTests()
{
#ifdef TESTDB
  sleep(2);

  runDBSysCommands();
  runTableQueryTests();

#endif
}

void runDBSysCommands()
{
  fprintf(stdout, "\n========================\n");
  fprintf(stdout, "DB System Tests");
  fprintf(stdout, "\n========================\n");
  fprintf(stdout, "Test create db: ");
  if (!krk_createdb("testdb"))
    fprintf(stdout, "P\n");
  else
    fprintf(stdout, "F\n");

  fprintf(stdout, "Test mount db: ");
  if (!krk_mountdb("testdb"))
    fprintf(stdout, "P\n");
  else
    fprintf(stdout, "F\n");

  fprintf(stdout, "Test add user: ");
  if (!krk_create_user("testuser", "pass"))
    fprintf(stdout, "P\n");
  else
    fprintf(stdout, "F\n");

  fprintf(stdout, "Test create table: ");
  if (!krk_createtb(""))
    fprintf(stdout, "P\n");
  else
    fprintf(stdout, "F\n");

  fprintf(stdout, "Test unmount db: ");
  if (!krk_umountdb("testdb"))
    fprintf(stdout, "P\n");
  else
    fprintf(stdout, "F\n");
  fprintf(stdout, "========================\n");
}

void runTableQueryTests()
{


  fprintf(stdout, "DB Table Query Tests");
  fprintf(stdout, "\n========================\n");

  fprintf(stdout, "\n========================\n");
}