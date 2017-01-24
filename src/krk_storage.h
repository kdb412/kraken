#pragma once

#include "global_types.h"
#include "storage_path.h"
#include <stdio.h>
#include <stdlib.h>

extern krk_db_path krk_dbpath;

// forward declarations of internal function
uint8_t _krk_mountdb(uchar *c);
uint8_t _krk_umountdb(uchar *c);
uint8_t _krk_createdb(uchar *c);
uint8_t _krk_createtb(uchar *c);

#define KRAKEN_ID "KRAKENDB"
#define KRAKEN_VER "0.1"

typedef struct _krk_rec_meta
{
  uint64_t tid_clinkid[200][200];
  char *cn[200][200];
  uint32_t ct[200][200];

} krk_recmeta;

/**
 * Tables are defined in the base.kr
 * after the first 30 bytes that identify the database
 * type, version and name.
 *
 * Tables are defined in blocks of 65K
 * They are formatted as such:
 *
 * - random 8byte int that identifies the file that stores
 * the table data
 * - 8 byte table id
 * - 20 bytes for the table name
 * - 8 bytes column id
 * - 20 bytes column name
 * - 4 bytes column type ...
 */
typedef struct _krk_table_meta
{
  krk_recmeta recmeta;
  pthread_mutex_t tbl_loc[200];
  uint64_t tableid[200];
  char *tablenm[200];
  FILE *tbl_files[200];
} krk_tablemeta;

/**
 * Database meta data begins in the folder in a file
 * called base.kr. This file is formatted as such:
 * dbtypename | dbversion | database name
 * 10 bytes for the database name
 * 10 bytes for the database version
 * 20 bytes for the database name
 *
 * ie. KRAKENDB | 0.1 | testdb
 *
 * Following this 40 bytes that identify the database type
 * are blocks of 65k bytes describing the tables in the database
 *
 */
typedef struct _krk_database_meta
{
  krk_tablemeta tbls;
  pthread_mutex_t db_loc;
  FILE *db_file;
  FILE *tx_log;
  krk_db_path *krk_path;
  char *dbname;
} krk_databasemeta;

uint8_t krk_createdb(uchar *c);
uint8_t krk_createtb(uchar *c);
uint8_t krk_mountdb(uchar *c);
uint8_t krk_umountdb(uchar *c);

krk_databasemeta krk_db;