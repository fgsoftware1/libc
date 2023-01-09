include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(include INTERFACE)
target_sources(include INTERFACE
    types.h
    stdarg.h
    stdio.h
    string.h
    stdlib.h
    ctype.h
)