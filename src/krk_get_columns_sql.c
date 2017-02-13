#include "parse.h"

void krk_get_columns_sql(char* s, krk_sql_token* tk)
{
  const uint8_t col_max = 200;
  uint8_t col_count = 0;
  uint8_t error_found = 0;
  char* tail = NULL;
  char* body = NULL;
  char buff[1024] = { 0 };

  if(tk->mode == SELECT) {
    if(!strncmp(s, "select ", strlen("select "))) {
      if(!body) {
        body = s;
        body += strlen("select ");
        tail = body;
      }
      while(1) {
        if((*body) != ' ' && (*body) != '\0' && (*body) != ',') {
          tail = body;
          while(1) {
            if(((*tail) == ',' || (*tail) == ' ') &&
                strncmp(body, "from", strlen("from"))) {
              if(col_count < col_max) {
                tk->cols[col_count] = (uint8_t*)malloc(tail - body + 1);
                if(tk->cols[col_count] != NULL)
                  memset(tk->cols[col_count], 0, tail - body);
                else
                  exit(1);

                strncpy(tk->cols[col_count], body, tail - body);
                col_count++;
                body = tail;
                break;
              }
            }
            if((*tail) == '\0')
              break;
            tail++;
          }
        }
        if((*body) == '\0' || !strncmp(body, "from", strlen("from")))
          break;
        body++;
      }
    }
    return;
  }

  if(tk->mode == CREATE) {
    strcat(buff, "create table ");
    if(strlen(tk->tblname) <= 0)
      return;
    strcat(buff, tk->tblname);
    strcat(buff, " (");

    if(!strncmp(s, buff, strlen(buff))) {
      if(!body) {
        body = &s[strlen(buff)];
        tail = body;
      }

      while(1) {
        if((*body) != ' ' && (*body) != '\0' && (*body) != ',') {
          tail = body;
          while(1) {
            if(((*tail) == ',' || (*tail) == ' ') &&
                strncmp(body, ")", strlen(")"))) {
              if(col_count < col_max) {
                tk->cols[col_count] = (uint8_t*)malloc(tail - body + 1);
                if(tk->cols[col_count] != NULL)
                  memset(tk->cols[col_count], 0, tail - body);
                else
                  exit(1);

                strncpy(tk->cols[col_count], body, tail - body);
                col_count++;
                body = tail;
                break;
              }
            }
            if((*tail) == '\0')
              break;
            tail++;
          }
        }
        if((*body) == '\0' || (*body) != ')')
          break;
        body++;
      }
    }
    return;
  }

  if(tk->mode == INSERT) {
    strcat(buff, "insert into ");
    if(strlen(tk->tblname) <= 0)
      return;
    strcat(buff, tk->tblname);
    strcat(buff, " (");

    if(strlen(s) <= strlen(buff))
      return;

    body = &s[strlen(buff)]+1;
    tail = body;
    col_count = 0;

    while(*tail != '\0' && *tail != ')') {

      while(*body == ' ' && *body != '\0')
        body++;

      if(*body == '\0')
        return;

      tail = body;

      while(*tail != ',' && *tail != ' ' && *tail != '\0' && *tail != ')')
        tail++;

      if(*tail == '\0')
        return;

      tk->cols[col_count] = (uint8_t*)malloc(tail - body + 1);
      if(tk->cols[col_count] != NULL)
        memset(tk->cols[col_count], 0, tail - body);
      else
        exit(1);

      strncpy(tk->cols[col_count], body, tail - body);
      col_count++;

      tail++;
      body = tail;
    }
    return;
  }
}
