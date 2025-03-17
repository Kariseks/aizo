#stl_alter / algorithms

set(SOURCES
    ${SOURCES}
    "${CMAKE_CURRENT_LIST_DIR}/sort.cpp"
    PARENT_SCOPE)

#tests
add_subdirectory("./test/")
set(TEST_SOURCES ${TEST_SOURCES} PARENT_SCOPE)
target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
