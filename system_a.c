#include "system_a.h"
#include "storage_path.h"

#include <stdio.h>

extern krk_db_path krk_dbpath;

uint8_t krk_login(uchar *user, uchar *pass)
{

    return 1;
}

uint8_t krk_logout(uchar *user)
{

    return 1;
}

// forward declaration of internal function
uint8_t _krk_create_user(uchar *user, uchar *pass);

uint8_t krk_create_user(uchar *user, uchar *pass)
{
    uint8_t ret = 1;
    uchar _user[20] = {0};
    uchar _pass[20] = {0};

    if (strlen(user) > 20 || strlen(pass) > 20)
        return ret;

    strncpy(_user, user, 20);
    strncpy(_pass, pass, 20);

    ret = _krk_create_user(_user, _pass);

    return ret;
}

uint8_t _krk_create_user(uchar *user, uchar *pass)
{
    uint8_t ret = 1;
    uint8_t write_flag = 1;
    uchar tmpBuff[40] = {0};
    int32_t counter = 0;
    char krk_base[4096] = {0};

    pthread_mutex_lock(&(krk_dbpath.spl));
    if (krk_dbpath.mounted == 1)
    {
        strcpy(krk_base, krk_dbpath.dbpath);
        strcat(krk_base, "/users.kr");
        FILE *fuser = fopen(krk_base, "r+b");

        // new file being created
        if (!fuser)
            fuser = fopen(krk_base, "w+b");

        if (!fuser)
            goto break_out;

        while (!fseek(fuser, counter, SEEK_SET))
        {
            if (fread(tmpBuff, 1, 40, fuser) != 40)
                break;

            if (!strncmp(tmpBuff, user, 20))
                write_flag = 0;

            counter += 40;
        }

        if (write_flag)
        {
            fwrite(user, 1, 20, fuser);
            fwrite(pass, 1, 20, fuser);
            ret = 0;
        }
        fclose(fuser);
    }
break_out:
    pthread_mutex_unlock(&(krk_dbpath.spl));

    return ret;
}