#stl_alter
set(LIB_NAME "stl_alter")
set(SOURCES "") #library sources files
add_library(${LIB_NAME})

set(TEST_NAME "stl_alter_test")
set(TEST_SOURCES "")    #test file of the library
add_executable(${TEST_NAME})
#==================================================================================================
add_subdirectory("./algorithms/")
add_subdirectory("./containers/")
#==================================================================================================
target_sources(${LIB_NAME} PRIVATE ${SOURCES} )
target_compile_features(${LIB_NAME} PRIVATE cxx_std_23)
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX) #i dont expect any cpp files in my lib, only templates
#target_sources(${LIB_NAME} PUBLIC ${SOURCES})
#==================================================================================================
#Library tests

add_subdirectory("./tests/")
target_sources(${TEST_NAME} PRIVATE ${TEST_SOURCES})

#adding all subfolder to target, in order to: allow to include a file without path (only Test file)
#target_include_directories(${TEST_NAME} PRIVATE ${TEST_INCLUDES}) test includes doesn't exists

target_link_libraries(${TEST_NAME} PUBLIC ${LIB_NAME} Catch2::Catch2WithMain)
enable_testing() #enables tests
find_package(Catch2 REQUIRED)
include(CTest)
