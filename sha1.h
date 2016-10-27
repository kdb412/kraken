#pragma once

typedef struct {
	unsigned int h0;
	unsigned int h1;
	unsigned int h2;
	unsigned int h3;
	unsigned int h4;
} DIGEST;

typedef struct {
	unsigned long long int size;
	unsigned long long int r_len;
	DIGEST hash;
} krk_sha;

void krk_nxtHash(krk_sha *ctx, char *data);
int krk_initSHA(krk_sha **ctx, unsigned long long int size);
void krk_hashStr(krk_sha *ctx, char *hashstr);
