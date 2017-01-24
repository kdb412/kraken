#include "storage_path.h"

int _krk_checkdbpath(char *p)
{
  DIR *_dbp = opendir(p);

  if (_dbp == NULL)
  {
    return 1;
  }
  closedir(_dbp);

  // configure the instance object's path
  memset(&krk_dbpath, 0, sizeof(krk_db_path));
  strncpy(krk_dbpath.dbpath, p, krk_MAX_DB_PATH);

  return 0;
}
