#include "global_types.h"

void krk_sql_spc_strip(char *s)
{
  uint8_t disable = 0;
  uint32_t count = 0;
  uint32_t len = strlen(s);
  char *tip = s;
  char *s_tmp = malloc(strlen(s) + 1);

  memset(s_tmp, 0, strlen(s) + 1);

  while (count < len - 1 && *tip != '\0' && *(tip + 1) != '\0')
  {
    if (*tip == '"' || *tip == '\'')
      disable = !disable;

    if (*tip == ' ' && count == 0) // remove prefix space
    {
      tip++;
      count++;
    }
    else if (*tip == ' ' && *(tip + 1) == ' ' && disable)
    {
      strncat(s_tmp, tip, 1);
      tip++;
      count++;
    }
    else if (*tip == ' ' && *(tip + 1) == ' ' && !disable)
    {
      tip++;
      count++;
    }
    else if (*tip != '\0')
    {
      strncat(s_tmp, tip, 1);
      tip++;
      count++;
    }
  }

  // copy last byte
  strncat(s_tmp, tip, 1);

  strcpy(s, s_tmp);
  free(s_tmp);
}
