
#include "random.h"
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef _WIN32
#include <process.h>
#endif

extern const unsigned char krk_b64[64];

unsigned char randbyte() {
	unsigned int cntr = 0;
	static unsigned int seed = 0;
	time_t rawtime;
	unsigned char timestr[255] =
			{0};
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
#ifdef _WIN32
	seed += _getpid();
#else
	seed += getpid();
#endif

	strcpy((char *) timestr, asctime(timeinfo));
	while (cntr < strlen(asctime(timeinfo))) {
		seed += timestr[cntr];
		cntr++;
	}
	cntr = 0;

	srand(seed);

	return krk_b64[rand() % 64];
}

unsigned int randint() {
	unsigned int cntr = 0;
	static unsigned int seed = 0;
	time_t rawtime;
	unsigned char timestr[255] =
			{0};
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
#ifdef __WINNT
	seed += _getpid();
#endif
#ifdef __linux
	seed += getpid();
#endif


	strcpy((char *) timestr, asctime(timeinfo));
	while (cntr < strlen(asctime(timeinfo))) {
		seed += timestr[cntr];
		cntr++;
	}
	cntr = 0;

	srand(seed);

	return rand() % 4294967296;

}