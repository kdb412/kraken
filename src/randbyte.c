#include "random.h"

uchar randbyte()
{
  uint32_t cntr = 0;
  static uint32_t seed = 0;
  time_t rawtime;
  uchar timestr[255] = { 0 };
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
#ifdef _WIN32
  seed += _getpid();
#else
  seed += getpid();
#endif

  strcpy((char*)timestr, asctime(timeinfo));
  while(cntr < strlen(asctime(timeinfo))) {
    seed += timestr[cntr];
    cntr++;
  }
  cntr = 0;

  srand(seed);

  return rand()%256;
}
