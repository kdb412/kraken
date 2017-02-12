#include "random.h"

uint32_t randint()
{
  uint32_t cntr = 0;
  static uint32_t seed = 0;
  time_t rawtime;
  uchar timestr[255] = { 0 };
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
#ifdef __WINNT
  seed += _getpid();
#endif
#ifdef __linux
  seed += getpid();
#endif

  strcpy((char*)timestr, asctime(timeinfo));
  while(cntr < strlen(asctime(timeinfo))) {
    seed += timestr[cntr];
    cntr++;
  }
  cntr = 0;

  srand(seed);

  return rand() % 4294967296;
}
