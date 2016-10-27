
#include "test.h"
#include "b64.h"
#include "sha1.h"
#include "global_types.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int krk_tst_b64() {
	uchar *enc_p = NULL;
	uchar *dec_p = NULL;

	uchar inputvector[][20] = {
			"",
			"f",
			"fo",
			"foo",
			"foob",
			"fooba",
			"foobar"
	};

	uchar outputvector[][20] = {
			"",
			"Zg==",
			"Zm8=",
			"Zm9v",
			"Zm9vYg==",
			"Zm9vYmE=",
			"Zm9vYmFy"
	};

	fprintf(stdout, "running encoding tests...\n");
	for (int i = 0; i < 7; i++) {

		fprintf(stdout, " encoding test %d => ", i + 1);
		krk_b64enc(inputvector[i],
				   &enc_p,
				   strlen(inputvector[i]));

		if (strcmp(enc_p, outputvector[i])) {
			fprintf(stdout, "failed\n");
			free(enc_p);
			return 1;
		}
		free(enc_p);
		fprintf(stdout, "passed\n");
	}

	fprintf(stdout, "running decoding tests...\n");
	for (int i = 0; i < 7; i++) {

		fprintf(stdout, " decoding test %d => ", i + 1);
		krk_b64dec(&dec_p,
				   outputvector[i],
				   strlen(outputvector[i]));

		if (strcmp(dec_p, inputvector[i])) {
			fprintf(stdout, "failed\n");
			free(dec_p);
			return 1;
		}
		free(dec_p);
		fprintf(stdout, "passed\n");
	}

	return 0;
}

int krk_tst_sha()
{
	uchar hashStr[50] = {0};
	krk_sha *hasht = NULL;
	uchar inputvector[][64] = {
			"",
			"The quick brown fox jumps over the lazy dog",
			"The quick brown fox jumps over the lazy cog",
	};

	uchar outputvector[][50] = {
			"da39a3ee5e6b4b0d3255bfef95601890afd80709",
			"2fd4e1c67a2d28fced849ee1bb76e7391b93eb12",
			"de9f2c7fd25e1b3afad3e85a0bd17d9b100db4b3"
	};

	fprintf(stdout, "running hash tests...\n");
	for (int i = 0; i < 3; i++)
	{
		fprintf(stdout, " hash test %d => ", i + 1);
		krk_initSHA(&hasht, strlen(inputvector[i]));
		krk_nxtHash(hasht, inputvector[i]);
		krk_hashStr(hasht, hashStr);

		if(strcmp(hashStr, outputvector[i]))
		{
			free(hasht);
			fprintf(stdout, "failed\n");
			return 1;
		}
		free(hasht);
		fprintf(stdout, "passed\n");
	}

	return 0;
}