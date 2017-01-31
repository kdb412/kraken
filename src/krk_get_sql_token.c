#include "parse.h"

krk_sql_token *krk_get_sql_token(char *s)
{
    krk_sql_token *token = NULL;

    // remove extra space in query
    krk_sql_spc_strip(s);

    // get the query mode - select, insert etc.
    int8_t mode = krk_get_sql_mode(s);
    if (mode <= 0)
        return NULL;

    token = (krk_sql_token *)calloc(1, sizeof(krk_sql_token));
    token->mode = mode;

    // get the table
    if (krk_get_table_sql(s, token))
    {
        if (token)
            free(token);
        token = NULL;
        printf("FREE\n");
        return token;
    }

    return token;
}
