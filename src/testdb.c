#include "testdb.h"
#include "krk_storage.h"
#include "krk_user.h"
#include "parse.h"

void runDBTests()
{
#ifdef TESTDB
  sleep(2);

  runTableNameQueryTests();
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
    fprintf(stderr, "F\n");

  fprintf(stdout, "Test mount db: ");
  if (!krk_mountdb("testdb"))
    fprintf(stdout, "P\n");
  else
    fprintf(stderr, "F\n");

  fprintf(stdout, "Test add user: ");
  if (!krk_create_user("testuser", "pass"))
    fprintf(stdout, "P\n");
  else
    fprintf(stderr, "F\n");

  fprintf(stdout, "Test create table: ");
  if (!krk_createtb("  create    table    starwars_character  (name varchar(200), id int, evil bool)"))
    fprintf(stdout, "P\n");
  else
    fprintf(stderr, "F\n");

  fprintf(stdout, "Test unmount db: ");
  if (!krk_umountdb("testdb"))
    fprintf(stdout, "P\n");
  else
    fprintf(stderr, "F\n");
  fprintf(stdout, "========================\n");
}

void runTableNameQueryTests()
{
  uint8_t columnCountPass = 0;
  uint8_t columnCount = 0;
  uint32_t totalTests = 0;
  int table_queries_column_count[] = {1, 3, 3, 3, 4, 2, 3, 3, 0, 0, 0, 0, 0, 0};
  char table_queries[][1024] = {
      // select
      "select * from table123",
      "table123",
      "   select col1, col2, col3 from userinfo",
      "userinfo",
      "select  fruit, vegetables, meats from   grocery_list",
      "grocery_list",
      "select a,b,c from alphabet_soup where   a in ('a','b','c',  'd')",
      "alphabet_soup",

      // insert
      "insert into foo_bar (column1, col_um2, foo_bar, bar_foo) values ('apple', 'banana', 'pineapple', 'cheese')",
      "foo_bar",
      "insert into insurance (accident, coverage) values (true, false)",
      "insurance",
      "insert into   stories (title, fantasy, ending) values ('fox and fiddle', true, 'the end')",
      "stories",
      "   insert   into   stories (title, fantasy, ending) values ('fox and fiddle', true, 'the end')",
      "stories",

      // delete
      "   delete from vulkan where col1 = 'apple'",
      "vulkan",
      "delete    from     romulan     where     ship != 'vulkan' or ship != 'enterprise'",
      "romulan",
      "delete from Customers where CustomerName='Alfreds Futterkiste' and ContactName='Maria Anders'",
      "Customers",

      // update
      "update customers set address = 'nepal' where id = 6",
      "customers",
      "update     heros set superpower = 'flight' where name = 'wolverine'",
      "heros",
      "    update evildoers set name = 'dr. strange' where lunatic = true",
      "evildoers",

      "FIN"};

  // count the total Tests
  for (int i = 0; strcmp("FIN", table_queries[i]); i += 2)
    totalTests = i / 2 + 1;

  fprintf(stdout, "\n========================\n");
  fprintf(stdout, "SQL Token Tests");
  fprintf(stdout, "\n========================\n");

  for (int i = 0; i < totalTests * 2 - 1; i += 2)
  {
    krk_sql_token *tk;
    tk = NULL;

    fprintf(stdout, "SQL Query %d/%d: ", i / 2 + 1, totalTests);

    tk = krk_get_sql_token(table_queries[i]);

    columnCount = 0;
    while ((tk->cols[columnCount]) != NULL)
      columnCount++;

    if (columnCount == table_queries_column_count[i / 2])
      columnCountPass = 1;
    else
      columnCountPass = 0;

    if (tk && !strcmp(tk->tblname, table_queries[i + 1]) && columnCountPass)
      fprintf(stdout, "P\n");
    else
      fprintf(stderr, "F\n");

    if (tk)
    {
      free(tk);
      tk = NULL;
    }
  }

  fprintf(stdout, "========================\n");
}
