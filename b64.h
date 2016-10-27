#pragma once

int krk_b64enc(unsigned char *data, unsigned char **t_b64, int sz);
int krk_b64dec(unsigned char **data, unsigned char *t_b64, int sz);