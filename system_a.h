#pragma once

#include "global_types.h"
#include <inttypes.h>

uint8_t krk_create_user(uchar *user, uchar *pass);
uint8_t krk_login(uchar *user, uchar *pass);
uint8_t krk_logout(uchar *user);