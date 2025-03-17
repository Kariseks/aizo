#containers
set(SOURCES ${SOURCES}
    #"${CMAKE_CURRENT_SOURCE_DIR}/node.h"
    #"${CMAKE_CURRENT_SOURCE_DIR}/SingleList.tpp"
    #"SingleList.h"
    #"node.h"
    #"array.h"
    PARENT_SCOPE)
target_include_directories(${LIB_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


add_subdirectory("./tests/")
set(TEST_SOURCES ${TEST_SOURCES} PARENT_SCOPE)



