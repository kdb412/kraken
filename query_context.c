
#include "query_context.h"
#include "global_types.h"
#include "k_login.h"
#include "k_logout.h"
#include "k_query.h"
#include "k_mount.h"
#include "k_dmount.h"
#include "k_stop.h"

uint8_t krk_context_parse(uint8_t *user,
                            uint8_t *context,
                            uint8_t *data,
                            uint16_t sz) {

    if(strncmp(context, str(k_login), 8))
    {
       k_login_f(user, data, sz);
    }
    if(strncmp(context, str(k_logout), 8))
    {
       k_logout_f(user, data, sz);
    }
    if(strncmp(context, str(k_query), 8))
    {
       k_query_f(user, data, sz);
    }
    if(strncmp(context, str(k_mount), 8))
    {
       k_mount_f(user, data, sz);
    }
    if(strncmp(context, str(k_dmount), 8))
    {
       k_dmount_f(user, data, sz);
    }
    if(strncmp(context, str(k_stop), 8))
    {
       k_stop_f(user, data, sz);
    }
}
