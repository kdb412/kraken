#include "parse.h"

krk_sql_token *krk_get_sql_token(char *s)
{
    char *modified_query = NULL;
    krk_sql_token *token = NULL;

    // remove extra space in query
    modified_query = krk_sql_spc_strip(s);
    
    if(!modified_query)
        return NULL;

    // get the query mode - select, insert etc.
    int8_t mode = krk_get_sql_mode(modified_query);
    if (mode <= 0)
        return NULL;

    token = (krk_sql_token *)calloc(1, sizeof(krk_sql_token));
    token->mode = mode;

    // get the table
    if (krk_get_table_sql(modified_query, token))
    {
        if (token)
            free(token);
        token = NULL;
        return token;
    }

    // get the columns
    krk_get_columns_sql(modified_query, token);
    free(modified_query);

    return token;
}
