file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/include/*.h")
file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

file(GLOB HEADER "${CMAKE_CURRENT_LIST_DIR}/include/ihandler.h")
add_custom_command(
        TARGET ${PROJECT_NAME} PRE_LINK
        COMMAND ${CMAKE_COMMAND} -E copy ${HEADER} "${CMAKE_SOURCE_DIR}/app/include"
        COMMAND ${CMAKE_COMMAND} -E copy ${HEADER} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ihandler.h"
)

if(RUNTIME_DLL)
set_property(TARGET ${PROJECT_NAME} PROPERTY
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")    
endif()
if(RUNTIME_STATIC)
set_property(TARGET ${PROJECT_NAME} PROPERTY
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")    
endif()