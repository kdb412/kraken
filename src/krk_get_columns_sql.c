#include "parse.h"

void krk_get_columns_sql(char *s, krk_sql_token *tk)
{
  const uint8_t col_max = 200;
  uint8_t col_count = 0;
  uint8_t error_found = 0;
  char *tail = NULL;
  char *body = NULL;
  char buff[1024] = {0};
  char buff2[1024] = {0};

  if (tk->mode == SELECT)
  {
    if (!strncmp(s, "select ", strlen("select ")))
    {
      if (!body)
      {
        body = s;
        body += strlen("select ");
        tail = body;
      }
      while (1)
      {
        if ((*body) != ' ' && (*body) != '\0' && (*body) != ',')
        {
          tail = body;
          while (1)
          {
            if (((*tail) == ',' || (*tail) == ' ') &&
                strncmp(body, "from", strlen("from")))
            {
              if (col_count < col_max)
              {
                tk->cols[col_count] = (uint8_t *)malloc(tail - body + 1);
                if (tk->cols[col_count] != NULL)
                  memset(tk->cols[col_count], 0, tail - body);
                else
                  exit(1);

                strncpy(tk->cols[col_count], body, tail - body);
                col_count++;
                body = tail;
                break;
              }
              else
                return;
            }
            if ((*tail) == '\0')
              break;
            tail++;
          }
        }
        if ((*body) == '\0' || !strncmp(body, "from", strlen("from")))
          break;
        body++;
      }
    }
    return;
  }

  if (tk->mode == CREATE)
  {
    uint8_t type_field = 0;
    uint8_t type_field_ret = 0;
    uint8_t col_tspecifier[100] = {0};
    strcat(buff, "create table ");
    strcat(buff2, "create table ");
    if (strlen(tk->tblname) <= 0)
      return;

    strcat(buff, tk->tblname);
    strcat(buff, " (");

    strcat(buff2, tk->tblname);
    strcat(buff2, "(");

    if (!strncmp(s, buff, strlen(buff)))
    {
      if (!body)
      {
        body = &s[strlen(buff)];
        tail = body;
      }
    }
    else if (!strncmp(s, buff2, strlen(buff2)))
    {
      body = &s[strlen(buff2)];
      tail = body;
    }

    while (1)
    {
      if ((*body) != ' ' && (*body) != '\0' && (*body) != ',')
      {
        tail = body;
        while (1)
        {
          if (((*tail) == ',' || (*tail) == ' ') &&
              strncmp(body, ")", strlen(")")))
          {

            if (!type_field)
            {
              type_field = 1;
              if (col_count < col_max)
              {
                tk->cols[col_count] = (uint8_t *)malloc(tail - body + 1);
                if (tk->cols[col_count] != NULL)
                  memset(tk->cols[col_count], 0, tail - body);
                else
                  exit(1);

                strncpy(tk->cols[col_count], body, tail - body);
                body = tail;
                break;
              }
              else
                return;
            }
            else
            {

              if (col_count < col_max)
              {
                type_field = 0;
                if (tail - body < 100)
                {
                  memset(&col_tspecifier[0], 0, 100);
                  strncpy(&col_tspecifier[0], body, tail - body);
                  type_field_ret = krk_get_column_type(col_tspecifier);
                  if (type_field_ret)
                    tk->col_typ[col_count] = type_field_ret;
                }
                body = tail;
                type_field = 0;
                col_count++;
              }
              else
                return;
            }
          }
          if ((*tail) == '\0')
            break;
          tail++;
        }
      }
      if ((*body) == '\0' || (*body) == ')')
        break;
      body++;
    }
    return;
  }

  if (tk->mode == INSERT)
  {
    memset(buff, 0, 1024);
    memset(buff2, 0, 1024);
    strcat(buff, "insert into ");
    strcat(buff2, "insert into ");
    if (strlen(tk->tblname) <= 0)
      return;
    strcat(buff, tk->tblname);
    strcat(buff2, tk->tblname);
    strcat(buff, " (");
    strcat(buff2, "(");

    // handle the case where no space between
    //  table name and first brace
    if (!strncmp(s, buff, strlen(buff)))
    {
      body = &s[strlen(buff)];
      if (strlen(s) <= strlen(buff))
        return;
    }
    else if (!strncmp(s, buff2, strlen(buff2)))
    {
      body = &s[strlen(buff2)];
      if (strlen(s) <= strlen(buff2))
        return;
    }

    tail = body;
    col_count = 0;

    while (*tail != '\0' && *tail != ')')
    {

      while ((*body == ' ' || *body == '(') && *body != '\0')
        body++;

      if (*body == '\0')
        return;

      tail = body;

      while (*tail != ',' && *tail != ' ' && *tail != '\0' && *tail != ')')
        tail++;

      if (*tail == '\0')
        return;

      if (col_count > col_max - 1)
        return;

      tk->cols[col_count] = (uint8_t *)malloc(tail - body + 1);
      if (tk->cols[col_count] != NULL)
        memset(tk->cols[col_count], 0, tail - body + 1);
      else
        exit(1);

      strncpy(tk->cols[col_count], body, tail - body);
      col_count++;

      if (*tail == '\0' || *tail == ')')
        return;

      tail++;
      body = tail;
    }
    return;
  }
}
