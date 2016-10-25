cmake_minimum_required(VERSION 3.6)
project(kraken)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES kraken.c kraken.h engine.c engine.h global_types.h query_s.c query_s.h)
add_executable(kraken ${SOURCE_FILES})

if (WIN32)
    target_link_libraries(kraken wsock32 ws2_32)
endif (WIN32)