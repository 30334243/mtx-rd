set(APP "app")
set(INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include/*.h")
file(GLOB HEADERS ${INCLUDE})
file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_executable(${APP} ${HEADERS} ${SOURCES})

add_dependencies(${APP} ${PROJECT_NAME})

target_include_directories(${APP} PRIVATE $<PATH:REMOVE_FILENAME,${INCLUDE}>)

if(RUNTIME_DLL)
set_property(TARGET ${APP} PROPERTY
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")    
endif()
if(RUNTIME_STATIC)
set_property(TARGET ${APP} PROPERTY
MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")    
endif()
