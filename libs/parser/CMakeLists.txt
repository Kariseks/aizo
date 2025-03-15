#parser
set(SOURCES ${SOURCES}
    "${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/parser.h"
    PARENT_SCOPE)

#==================================================================================================
add_subdirectory("./tests/")
set(TEST_SOURCES ${SOURCES} PARENT_SCOPE)


