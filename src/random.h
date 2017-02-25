#pragma once

#include "global_types.h"
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

uchar randb64();
uchar randbyte();
uint32_t randint();

#ifdef _WIN32
#include <process.h>
#endif

extern const uchar krk_b64[64];
