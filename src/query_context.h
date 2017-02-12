#pragma once

#include <inttypes.h>

typedef enum {
  k_login = 900,
  k_logout,
  k_query,
  k_mount,
  k_umount,
  k_stop
} krk_contexts;

uint8_t krk_context_parse(int32_t* sock,
    uint8_t* user,
    uint8_t* context,
    uint8_t* data,
    uint16_t sz);
