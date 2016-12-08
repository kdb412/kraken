#include "parse.h"

void krk_sstrip_extra_spaces(char *s)
{
  char *tip = s;
  char s_tmp[strlen(s)+1];

  memset(s_tmp, 0, strlen(s)+1);

  while(tip != '\0' && tip+1 != '\0')
    {
      if(tip == ' ' && tip+1 != ' ')
	{
	  strncat(s_tmp, tip, 1);
	}
      else if( tip == ' ')
	{
	  tip++;
	}
      else
	strncat(s_tmp, tip, 1);
	  
    }
  strcpy(s, s_tmp);
  free(s_tmp);
}
