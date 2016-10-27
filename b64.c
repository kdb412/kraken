
#include "b64.h"
#include <stdlib.h>

const unsigned char krk_b64[64] = \
        {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O',
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
		'c', 'd',
		'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
		'r', 's',
		't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5',
		'6', '7',
		'8', '9', '+', '/'
};

int base64DecHelper(unsigned char byte) {
	int cntr = 0;
	while (cntr < 64) {
		if (krk_b64[cntr] == byte)
			return cntr;
		cntr++;
	}
	return 0;
}

int krk_b64enc(unsigned char *data, unsigned char **t_b64, int sz) {
	int b64Size = 0;
	int dat_cntr = 0;
	int b64_cntr = 0;
	unsigned char *dataPtr = 0;
	int suffixCnt = 0;

	b64Size = (sz / 3) * 4;
	b64Size += ((sz % 3) != 0) ? 4 : 0;

	suffixCnt = 0;

	switch (sz % 3) {
		case 2:
			suffixCnt = 1;
			break;
		case 1:
			suffixCnt = 2;
			break;
		default:
			break;
	}

	(*t_b64) = (unsigned char *) calloc(sizeof(char), b64Size + 3);
	dataPtr = data;

	while (dat_cntr < sz) {
		if ((dat_cntr == (sz - 1)) || (dat_cntr == (sz - 2))) {
			switch (suffixCnt) {
				case 1:
					(*t_b64)[b64_cntr + 0] = krk_b64[(*dataPtr) >> 2];
					(*t_b64)[b64_cntr + 1] = krk_b64[(((*dataPtr) & 0x03) << 4)
													 |
													 (((*(dataPtr + 1)) & 0xf0)
															 >> 4)];
					(*t_b64)[b64_cntr + 2] = krk_b64[
							(((*(dataPtr + 1)) & 0x0f) << 2)
							| (((*(dataPtr + 2)) & 0xc0) >> 6)];
					dat_cntr = sz;
					break;
				case 2:
					(*t_b64)[b64_cntr + 0] = krk_b64[(*dataPtr) >> 2];
					(*t_b64)[b64_cntr + 1] = krk_b64[(((*dataPtr) & 0x03) << 4)
													 |
													 (((*(dataPtr + 1)) & 0xf0)
															 >> 4)];
					dat_cntr = sz;
					break;
				case 0:
					break;
				default:
					break;
			}

		} else {
			(*t_b64)[b64_cntr + 0] = krk_b64[(*dataPtr) >> 2];
			(*t_b64)[b64_cntr + 1] = krk_b64[(((*dataPtr) & 0x03) << 4)
											 |
											 (((*(dataPtr + 1)) & 0xf0) >> 4)];
			(*t_b64)[b64_cntr + 2] = krk_b64[(((*(dataPtr + 1)) & 0x0f) << 2)
											 |
											 (((*(dataPtr + 2)) & 0xc0) >> 6)];
			(*t_b64)[b64_cntr + 3] = krk_b64[(*(dataPtr + 2)) & 0x3f];

			dataPtr += 3;
			b64_cntr += 4;
			dat_cntr += 3;
		}
	}

	if (suffixCnt == 1)
		(*t_b64)[b64Size - 1] = '=';
	if (suffixCnt == 2) {
		(*t_b64)[b64Size - 2] = '=';
		(*t_b64)[b64Size - 1] = '=';
	}

	return b64Size;
}

int krk_b64dec(unsigned char **data, unsigned char *t_b64, int sz) {
	int decSz = 0;
	int dat_cntr = 0;
	int b64_cntr = 0;
	int cntr = 0;
	unsigned char *b64_dataPtr = 0;
	unsigned char *dataPtr = 0;
	int suffixCnt = 0;
	int a = 0, b = 0, c = 0, d = 0;
	int suffixAdjuster = 0;

	suffixCnt = 0;
	cntr = sz;
	while (cntr > sz - 3) {
		if (t_b64[cntr - 1] == '=')
			suffixCnt++;
		cntr--;
	}

	suffixAdjuster = 0;
	suffixAdjuster += (suffixCnt != 0) ? 4 : 0;

	switch (suffixCnt) {
		case 2:
			decSz += 1;
			break;
		case 1:
			decSz += 2;
			break;
	}

	decSz += (((sz - suffixAdjuster) / 4) * 3);
	(*data) = (unsigned char *) calloc(sizeof(unsigned char), decSz + 3);
	dataPtr = *data;
	b64_dataPtr = t_b64;

	while (b64_cntr < sz - suffixAdjuster) {
		a = base64DecHelper(*b64_dataPtr);
		b = base64DecHelper(*(b64_dataPtr + 1));
		c = base64DecHelper(*(b64_dataPtr + 2));
		d = base64DecHelper(*(b64_dataPtr + 3));

		*dataPtr = (((a) << 2) & 0xfc) | (((b) >> 4) & 0x03);
		*(dataPtr + 1) = (((b) << 4) & 0xf0) | (((c) >> 2) & 0x0f);
		*(dataPtr + 2) = (((c) << 6) & 0xc0) | (((d)) & 0x3f);
		dataPtr += 3;
		dat_cntr += 3;
		b64_dataPtr += 4;
		b64_cntr += 4;
	}

	switch (suffixCnt) {
		case 2:
			a = base64DecHelper(*b64_dataPtr);
			b = base64DecHelper(*(b64_dataPtr + 1));
			*dataPtr = (((a) << 2) & 0xfc) | (((b) >> 4) & 0x03);
			break;
		case 1:
			a = base64DecHelper(*b64_dataPtr);
			b = base64DecHelper(*(b64_dataPtr + 1));
			c = base64DecHelper(*(b64_dataPtr + 2));
			*dataPtr = (((a) << 2) & 0xfc) | (((b) >> 4) & 0x03);
			*(dataPtr + 1) = (((b) << 4) & 0xf0) | (((c) >> 2) & 0x0f);
			break;
	}

	return decSz;
}