#stl_alter / algorithms

set(SOURCES
    ${SOURCES}

    PARENT_SCOPE)

#tests
add_subdirectory("./test/")
set(TEST_SOURCES ${TEST_SOURCES} PARENT_SCOPE)
target_include_directories(${LIB_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/")
