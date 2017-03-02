#include "krk_storage.h"

uint8_t _krk_createdb(uchar *c)
{
  char krk_base[4096] = {0};
  char krk_header[40] = {0};
  char krk_zero_table_data[65000] = {0};

  uint64_t bytes_read = 0;

  if (krk_dbpath.mounted || strnlen(c, 20) >= 20)
  {
    return 1;
  }

  /*
   * create a database only if the
   * no file exists (avoid corruption of existing file)
   */
  memset(&krk_db, 0, sizeof(krk_base));
  strcpy(krk_base, krk_dbpath.dbpath);
  strcat(krk_base, "/base.kr");
  krk_db.db_file = fopen(krk_base, "rb");
  if (krk_db.db_file)
  {
    fclose(krk_db.db_file);
    krk_db.db_file = NULL;
    return 1;
  }

  krk_db.db_file = fopen(krk_base, "ab+");
  if (!krk_db.db_file)
  {
    return 1;
  }

  /*
   * create the base database file
   */
  strcpy(krk_header, KRAKEN_ID);
  strcpy(&krk_header[10], KRAKEN_VER);
  strcpy(&krk_header[20], c);

  size_t ret = fwrite(krk_header, 1, 40, krk_db.db_file);
  if (ret != 40)
  {
    fclose(krk_db.db_file);
    return 1;
  }

  // zero out space where table info will be
  // 13MB roughly
  for (int i = 0; i < 200; i++)
    fwrite(krk_zero_table_data, 1, 65535, krk_db.db_file);

  fclose(krk_db.db_file);

  // create default admin
  krk_create_user("sa", "sa");
  return 0;
}
