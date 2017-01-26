#pragma once

#include "global_types.h"

enum _krk_sql_logic
{
    KRK_AND = 0,
    KRK_OR
} krk_sql_logic;

enum _krk_sql_alogic
{
    KRK_GT = 10,
    KRK_LT,
    KRK_EQ,
    KRK_NEQ
} krk_sql_alogic;

typedef struct _krk_sql_token
{
    /* 
        select <cols> from <table>
        select <cols> from <table> where <col> = <col_vals>
        select <cols> from <table> where <col> = <col_vals> and <col> != <col_vals>
        
        insert into <table> (col,col..) values (val1,val2,..)
        delete from <table> where <col> = <col_vals> or <col> = <col_val>
        update <table> set <col>=<col_val>, <col>=<col_val> where <col>=<col_val> and <col>=<vol_val>
    */

    // select, insert, update, delete
    uint8_t mode[6];

    // column names
    uint8_t *cols[200];

    // column values
    uint8_t *col_vals[200];

    // ie where col9
    uint8_t *where_col[200];

    // ie where col9 [=|!=|<|>]
    uint16_t where_logicop[200];

    // ie where col9 [=|!=|<|>] <foo>
    uint8_t *where_vals[200];

} krk_sql_token;

void krk_sql_spc_strip(char *s);
krk_sql_token* krk_get_sql_token(char *s);
