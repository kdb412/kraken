
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "kraken.h"
#include "storage_path.h"
#include "test.h"


k_byte KRK_SIGNAL = '\0';

void usage() {
    char GNU_TEXT[] =
            {
                "krakensql is a simple RDBMS with simplicity in mind\n"
                "Copyright (C) 2016 skullybox@gmx.com\n\n"

                "This program is free software: you can redistribute it and/or modify\n"
                "it under the terms of the GNU General Public License as published by\n"
                "the Free Software Foundation, either version 3 of the License, or\n"
                "(at your option) any later version.\n\n"

                "This program is distributed in the hope that it will be useful,\n"
                "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
                "GNU General Public License for more details.\n\n"
            };

    fprintf(stdout, "\n%s usage: kraken <DB folder path>\n", GNU_TEXT);
}

void krk_signal(int sig) {
    if (!KRK_SIGNAL) {
        KRK_SIGNAL = 'm';
    }
}

void krk_signal_configure() {
    signal(SIGINT, krk_signal);
    signal(SIGABRT, krk_signal);
    signal(SIGTERM, krk_signal);
    signal(SIGSEGV, krk_signal);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        usage();
        return 1;
    }

    krk_signal_configure();

    // run some integrity tests
    fprintf(stdout, "starting integrity tests\n");
    if(krk_tst_b64() || krk_tst_sha() || krk_encryption_test())
    {
        return 1;
    }

    if (krk_prepstoragepath(argv[1], strlen(argv[1])))
        return 1;

    while (!KRK_SIGNAL) {
        sleep(1);
    }

    // stop database engine
    krk_unprepstoragepath();

    return 0;
}
