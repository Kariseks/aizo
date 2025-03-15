#libs
add_subdirectory("./parser/")
add_subdirectory("./stl_alter/")


add_subdirectory("./tests")
set(TEST_SOURCES ${SOURCES} PARENT_SCOPE)


