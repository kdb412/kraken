
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "kraken.h"
#include "engine.h"
#include "global_types.h"

byte KRK_SIGNAL = '\0';

void usage()
{
	fprintf(stdout, "\n usage: kraken <DB folder path>\n");
}

void krk_signal(int sig)
{
	if(!KRK_SIGNAL)
	{
		fprintf(stderr, "caugh signal %d ...\n", sig);
		KRK_SIGNAL = 'm';
	}
}

void krk_signal_configure()
{
	signal(SIGINT, krk_signal);
	signal(SIGABRT, krk_signal);
	signal(SIGTERM, krk_signal);
	signal(SIGSEGV, krk_signal);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		usage();
		return 1;
	}

	krk_signal_configure();

	if(krk_engineinit(argv[1], strlen(argv[1])))
		return 1;

	while(!KRK_SIGNAL) {
		sleep(1);
	}

	return 0;
}
