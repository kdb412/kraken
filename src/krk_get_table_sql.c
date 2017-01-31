#include "parse.h"

uint8_t krk_get_table_sql(char *s, krk_sql_token *tk)
{
    char *tmpPtr = s;
    char *b_tmpPtr = s;
    uint32_t len = strlen(s);
    uint32_t count = 0;

    if (tk->mode == SELECT || tk->mode == DELETE)
    {
        while (count < len - 6 && (*tmpPtr) != '\0')
        {
            if (!strncmp(tmpPtr, " from ", 6))
            {
                tmpPtr += 6;
                count += 6;
                b_tmpPtr = tmpPtr;

                while (1)
                {
                    if (((*tmpPtr) == ' ' || (*tmpPtr) == '\0') && tmpPtr - b_tmpPtr <= 200)
                    {
                        strncpy(tk->tblname, b_tmpPtr, tmpPtr - b_tmpPtr);
                        return 0;
                    }
                    tmpPtr++;
                }
            }

            count++;
            tmpPtr++;
        }
        return 1;
    }

    if (tk->mode == INSERT)
    {
        while (count < len - 6 && (*tmpPtr) != '\0')
        {
            if (!strncmp(tmpPtr, " into ", 6))
            {
                tmpPtr += 6;
                count += 6;
                b_tmpPtr = tmpPtr;

                while (1)
                {
                    if (((*tmpPtr) == ' ' || (*tmpPtr) == '\0') && tmpPtr - b_tmpPtr <= 200)
                    {
                        strncpy(tk->tblname, b_tmpPtr, tmpPtr - b_tmpPtr);
                        return 0;
                    }
                    tmpPtr++;
                }
            }

            count++;
            tmpPtr++;
        }
        return 1;
    }

    if (tk->mode == UPDATE)
    {
        while (count < len - 7 && (*tmpPtr) != '\0')
        {
            if (!strncmp(tmpPtr, "update ", 7))
            {
                tmpPtr += 6;
                count += 6;
                b_tmpPtr = tmpPtr;

                while (1)
                {
                    if (((*tmpPtr) == ' ' || (*tmpPtr) == '\0') && tmpPtr - b_tmpPtr <= 200)
                    {
                        strncpy(tk->tblname, b_tmpPtr, tmpPtr - b_tmpPtr);
                        return 0;
                    }
                    tmpPtr++;
                }
            }

            count++;
            tmpPtr++;
        }
        return 1;
    }

    return 1;
}
