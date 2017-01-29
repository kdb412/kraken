#include "parse.h"

uint8_t krk_get_table_sql(char *s, krk_sql_token *tk)
{
    char *tmpPtr = s;
    char *e_tmpPtr = s;
    if (tk->mode == SELECT || tk->mode == DELETE)
    {
        while (tmpPtr != '\0')
        {
            if (!strncmp(tmpPtr, " from ", 6))
            {
            }

            tmpPtr += 6;
        }
    }

    if (tk->mode == INSERT)
    {
        while (tmpPtr != '\0')
        {
            if (!strncmp(tmpPtr, " into ", 6))
            {
            }

            tmpPtr += 6;
        }
    }

    if (tk->mode == UPDATE)
    {
        while (tmpPtr != '\0')
        {
            if (!strncmp(tmpPtr, "update ", 7))
            {
            }

            tmpPtr += 7;
        }
    }

    return 1;
}
