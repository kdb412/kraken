#include "krk_storage.h"

uint8_t _krk_umountdb(uchar* c)
{

  if(strnlen(c, 20) > 20 || strncmp(krk_db.dbname, c, 20) ||
      !krk_dbpath.mounted)
    return 1;

  // clear record meta data
  for(int i = 0; i < 200; i++) {
    for(int j = 0; j < 200; j++) {
      if(krk_db.tbls.recmeta.cn[i][j]) {
        free(krk_db.tbls.recmeta.cn[i][j]);
        krk_db.tbls.recmeta.cn[i][j] = 0;
      }
    }
  }
  memset(&krk_db.tbls.recmeta.tid_clinkid, 0,
      sizeof(krk_db.tbls.recmeta.tid_clinkid));
  memset(&krk_db.tbls.recmeta.ct, 0, 200);

  // clear table meta data and close table files
  for(int i = 0; i < 200; i++) {
    if(krk_db.tbls.tbl_files[i]) {
      krk_db.tbls.tableid[i] = 0;
      free(krk_db.tbls.tablenm[i]);
      krk_db.tbls.tablenm[i] = 0;
      fclose(krk_db.tbls.tbl_files[i]);
      krk_db.tbls.tbl_files[i] = 0;
    }
  }

  // close db file
  if(krk_db.db_file) {
    fclose(krk_db.db_file);
    krk_db.db_file = 0;
    free(krk_db.dbname);
    krk_db.dbname = 0;
  }

  krk_dbpath.mounted = 0;
  return 0;
}
