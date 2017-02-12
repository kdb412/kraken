#include "krk_user.h"

uint8_t _krk_create_user(uchar* user, uchar* pass)
{
  uint8_t ret = 1;
  uint8_t write_flag = 1;
  uchar tmpBuff[40] = { 0 };
  int32_t counter = 0;
  char krk_base[4096] = { 0 };
  static pthread_mutex_t createUserLock;

  pthread_mutex_lock(&createUserLock);

  strcpy(krk_base, krk_dbpath.dbpath);
  strcat(krk_base, "/users.kr");
  FILE* fuser = fopen(krk_base, "a+b");

  if(!fuser) {
    pthread_mutex_unlock(&createUserLock);
    goto break_out;
  }

  while(!fseek(fuser, counter, SEEK_SET)) {
    if(fread(tmpBuff, 1, 40, fuser) != 40)
      break;

    if(!strncmp(tmpBuff, user, 20))
      write_flag = 0;

    counter += 40;
  }

  if(write_flag) {
    fwrite(user, 1, 20, fuser);
    fwrite(pass, 1, 20, fuser);
    ret = 0;
  }
  fclose(fuser);
  pthread_mutex_unlock(&createUserLock);

break_out:

  return ret;
}
