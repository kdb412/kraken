cmake_minimum_required(VERSION 3.6)
project(kraken)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -w")

set(SOURCE_FILES  b64.c b64.h engine.c engine.h global_types.h k_dmount.c k_dmount.h k_login.c k_login.h k_logout.c k_logout.h k_mount.c k_mount.h k_query.c k_query.h kraken.c kraken.h k_stop.c k_stop.h query_context.c query_context.h query_s.c query_s.h random.c random.h sha1.c sha1.h test.c test.h )
add_executable(kraken ${SOURCE_FILES})

if (WIN32)
    target_link_libraries(kraken wsock32 ws2_32)
else()
    target_link_libraries(kraken pthread pthread)
endif (WIN32)
