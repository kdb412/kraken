#pragma once

#include "global_types.h"
#include "storage_path.h"
#include <stdio.h>

typedef struct _krk_rec_meta
{
    uint64_t tid_clinkid [200][200];
    char *cn [200][200];
    uint16_t ct[200][200];

} krk_recmeta;

typedef struct _krk_table_meta
{
    krk_recmeta recmeta;
    pthread_mutex_t tbl_loc[200];
    uint64_t tableid[200];
    char *tablenm[200];
    FILE *tbl_files[200];
} krk_tablemeta;

typedef struct _krk_database_meta
{
    krk_tablemeta tbls;
    pthread_mutex_t db_loc;
    FILE *db_file;
    FILE *tx_log;
    krk_db_path *krk_path;
} krk_databasemeta;

uint8_t krk_createdb(uchar *c);
uint8_t krk_mountdb(uchar *c);
uint8_t krk_umountdb(uchar *c);