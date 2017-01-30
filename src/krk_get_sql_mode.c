#include "parse.h"

int8_t krk_get_sql_mode(char *s)
{
    int8_t ret = -1;

    if (!strncmp(s, "select", 6))
    {
        ret = SELECT;
        return ret;
    }

    if (!strncmp(s, "insert", 6))
    {
        ret = INSERT;
        return ret;
    }

    if (!strncmp(s, "update", 6))
    {
        ret = UPDATE;
        return ret;
    }

    if (!strncmp(s, "delete", 6))
    {
        ret = DELETE;
        return ret;
    }

    return ret;
}