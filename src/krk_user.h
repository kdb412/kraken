#pragma once

#include "global_types.h"
#include "storage_path.h"
#include <inttypes.h>
#include <stdio.h>

extern krk_db_path krk_dbpath;

uint8_t krk_create_user(uchar* user, uchar* pass);
uint8_t krk_login(uchar* user, uchar* pass);
uint8_t krk_logout(uchar* user);