
#include "query_context.h"
#include "global_types.h"

uint8_t krk_context_parse(uint8_t *context,
						  uint8_t *data,
						  uint16_t sz) {

	if(strncmp(context, str(k_login), 8))
	{

	}
	else if(strncmp(context, str(k_loout), 8))
	{

	}
	else if(strncmp(context, str(k_query), 8))
	{

	}
	else if(strncmp(context, str(k_mount), 8))
	{

	}
	else if(strncmp(context, str(k_dmount), 8))
	{

	}
	else if(strncmp(context, str(k_stop), 8))
	{

	}

	return 0;
}
