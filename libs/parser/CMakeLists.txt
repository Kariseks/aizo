#parser
set(SOURCES ${SOURCES}
    "parser.cpp" "parser.h"
    PARENT_SCOPE)

#==================================================================================================
add_subdirectory("./tests/")
set(TEST_SOURCES ${SOURCES} PARENT_SCOPE)


