include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(src OBJECT
    stdio.c
    string.c
    stdlib.c
    ctype.c
)