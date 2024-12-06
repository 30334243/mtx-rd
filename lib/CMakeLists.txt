file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/include/*.h")
file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_library(${MTX_LIB} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${MTX_LIB} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

message(STATUS "${CMAKE_BUILD_TYPE}")

file(GLOB HEADER_MTX_LIB "${CMAKE_CURRENT_LIST_DIR}/include/ihandler.h")
add_custom_command(
        TARGET ${MTX_LIB} PRE_LINK
        COMMAND ${CMAKE_COMMAND} -E copy ${HEADER_MTX_LIB} "${CMAKE_SOURCE_DIR}/app/include"
        COMMAND ${CMAKE_COMMAND} -E copy ${HEADER_MTX_LIB} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/ihandler.h"
)

set_property(TARGET ${MTX_LIB} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")