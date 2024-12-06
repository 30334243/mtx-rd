cmake_minimum_required(VERSION 3.24)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(mtx)

set(CMAKE_CXX_STANDARD 17)

set(MTX_LIB ${PROJECT_NAME}_lib)
add_subdirectory(lib)

set(APP ${PROJECT_NAME}_app)
add_subdirectory(app)
