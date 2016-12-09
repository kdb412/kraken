#include "parse.h"

void krk_sstrip_extra_spaces(char *s)
{
  uint8_t disable = 0;
  char *tip = s;
  char s_tmp[strlen(s)+1];

  memset(s_tmp, 0, strlen(s)+1);

  while(tip != '\0' && tip+1 != '\0')
    {
      if(tip == '"' || tip == '\'')
	disable = !disable;
      
      if(tip == ' ' && tip+1 == ' ' && disable)
	{
	  strncat(s_tmp, tip, 1);
	  tip++;
	}
      else if( tip == ' ' && tip+1 == ' ' && !disable)
	{
	  tip++;
	}
      else
	{
	strncat(s_tmp, tip, 1);
	tip++;
	}
	  
    }
  strcpy(s, s_tmp);
  free(s_tmp);
}
