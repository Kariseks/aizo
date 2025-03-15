#stl_alter / algorithms

set(SOURCES ${SOURCES}

    PARENT_SCOPE)

#tests
add_subdirectory("./test/")
set(TEST_SOURCES ${TEST_SOURCES} PARENT_SCOPE)
