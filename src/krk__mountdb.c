#include "krk_storage.h"

uint8_t _krk_mountdb(uchar* c)
{
#define krk_tbl_block_sz 65000
  char krk_base[4096] = { 0 };
  char krk_header[40] = { 0 };
  char krk_tblinfo[krk_tbl_block_sz] = { 0 };

  uint64_t bytes_read = 0;

  if(krk_dbpath.mounted || strnlen(c, 20) >= 20)
    return 1;

  // mount the database
  memset(&krk_db, 0, sizeof(krk_base));
  strcpy(krk_base, krk_dbpath.dbpath);
  strcat(krk_base, "/base.kr");
  krk_db.db_file = fopen(krk_base, "rb");
  if(!krk_db.db_file)
    return 1;

  // read the base.kr file
  fread(krk_header, 1, 30, krk_db.db_file);

  // validate header and database name
  if(strncmp(krk_header, KRAKEN_ID, strlen(KRAKEN_ID)) ||
      strncmp(&krk_header[10], KRAKEN_VER, strlen(KRAKEN_VER)) ||
      strncmp(&krk_header[20], c, 20)) {
    fclose(krk_db.db_file);
    krk_db.db_file = NULL;
    return 1;
  }

  // set db name
  krk_db.dbname = malloc(strlen(c) + 1);
  strcpy(krk_db.dbname, c);

  uint32_t counter = 0;
  bytes_read = fread(krk_tblinfo, 1, krk_tbl_block_sz, krk_db.db_file);

  while(bytes_read == krk_tbl_block_sz && counter < 200) {
    // get table info
    krk_db.tbls.tableid[counter] = (uint64_t)(*krk_tblinfo);
    krk_db.tbls.tablenm[counter] = malloc(strnlen(&krk_tblinfo[8], 20));
    strncpy(krk_db.tbls.tablenm[counter], &krk_tblinfo[8],
        strnlen(&krk_tblinfo[8], 20));

    // open table file
    char tableFile[30] = { 0 };
    sprintf(tableFile, "%020llu", krk_db.tbls.tableid[counter]);
    krk_db.tbls.tbl_files[counter] = fopen(tableFile, "ab+");
    if(!krk_db.tbls.tbl_files[counter]) {
      // TODO: undo allocation of existing parsing
      _krk_umountdb(c);
      return 1;
    }

    // load column definitions
    uint32_t column_counter = 0;
    uint64_t _c_id = 0;
    uint32_t _offset = 28; // tableid + tablenm
    while(column_counter < 200 && _offset < krk_tbl_block_sz) {

      // column id
      _c_id = *((uint64_t*)&(krk_tblinfo[_offset]));
      if(_c_id == 0)
        break;
      krk_db.tbls.recmeta.tid_clinkid[counter][column_counter] = _c_id;

      // column name
      _offset += 8;
      krk_db.tbls.recmeta.cn[counter][column_counter] =
          malloc(strnlen(&krk_tblinfo[_offset], 20));

      strncpy(krk_db.tbls.recmeta.cn[counter][column_counter],
          &krk_tblinfo[_offset], strnlen(&krk_tblinfo[_offset], 20));

      // column type
      _offset += 20;
      krk_db.tbls.recmeta.ct[counter][column_counter] =
          *((uint32_t*)&(krk_tblinfo[_offset]));

      _offset += 4;
      column_counter++;
    }

    counter++;
  }

  return 0;
}