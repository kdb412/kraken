#include "testdb.h"
#include "krk_storage.h"
#include "krk_user.h"
#include "parse.h"

void runDBTests()
{
#ifdef TESTDB
  sleep(2);

  runSelectTableQueryTests();
  runDBSysCommands();

#endif
}

void runDBSysCommands()
{
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

void runSelectTableQueryTests()
{
  uint32_t totalTests = 0;
  char table_queries[][1024] = {
      "select * from table123",
      "table123",
      " select col1, col2, col3 from userinfo",
      "userinfo",
      "select  fruit, vegetables, meats from   grocery_list",
      "grocery_list",
      "select a,b,c from alphabet_soup where   a in ('a','b','c',  'd')",
      "alphabet_soup",
      "FIN"};

  // count the total Tests
  for (int i = 0; strcmp("FIN", table_queries[i]); i += 2)
    totalTests = i / 2 + 1;

  fprintf(stdout, "\n========================\n");
  fprintf(stdout, "[Table name] SQL Token Tests");
  fprintf(stdout, "\n========================\n");

  for (int i = 0; i < totalTests * 2 - 1; i += 2)
  {
    krk_sql_token *tk;
    tk = NULL;

    fprintf(stdout, "Table Select Query %d/%d: ", i / 2 + 1, totalTests);

    tk = krk_get_sql_token(table_queries[i]);

    if (tk && !strcmp(tk->tblname, table_queries[i+1]))
      fprintf(stdout, "P\n");
    else
      fprintf(stdout, "F\n");

    if (tk)
    {
      free(tk);
      tk = NULL;
    }
  }

  fprintf(stdout, "========================\n");
}