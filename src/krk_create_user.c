#include "krk_user.h"

// forward declaration of internal function
uint8_t _krk_create_user(uchar* user, uchar* pass);

uint8_t krk_create_user(uchar* user, uchar* pass)
{
  uint8_t ret = 1;
  uchar _user[20] = { 0 };
  uchar _pass[20] = { 0 };

  if(strlen(user) > 20 || strlen(pass) > 20)
    return ret;

  strncpy(_user, user, 20);
  strncpy(_pass, pass, 20);

  ret = _krk_create_user(_user, _pass);

  return ret;
}
