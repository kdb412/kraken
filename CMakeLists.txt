cmake_minimum_required(VERSION 3.6)
project(kraken)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -w")

set(SOURCE_FILES kraken.c kraken.h engine.c engine.h global_types.h query_s.c query_s.h b64.c b64.h random.c random.h test.c test.h sha1.c sha1.h)
add_executable(kraken ${SOURCE_FILES})

if (WIN32)
    target_link_libraries(kraken wsock32 ws2_32)
else()
    target_link_libraries(kraken pthread pthread)
endif (WIN32)