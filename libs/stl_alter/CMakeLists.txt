#stl_alter
set(SOURCES "")
add_subdirectory("./algorithms/")
add_subdirectory("./containers/")

add_library("stl_alter" STATIC ${SOURCES})
