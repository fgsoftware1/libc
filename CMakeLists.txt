cmake_minimum_required(VERSION 3.14)
project(libc VERSION 1.0.0 LANGUAGES C)

if(CMAKE_C_COMPILER)
    set(CMAKE_C_STANDARD 11)
    enable_language(C)
    add_compile_options(-m32 -std=c11 -ffreestanding -c)
    add_link_options(-m elf_i386 -nostdlib)
elseif()
    message(FATAT_ERROR "ERROR: No C compiler found! Can't continue!")
endif()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/include)

add_library(c STATIC
    src/stdio.c
    src/string.c
    src/stdlib.c
    src/ctype.c
)

target_compile_definitions(c PRIVATE __is_libc=1)