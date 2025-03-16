cmake_minimum_required(VERSION 3.16)

project(aizo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES "")   #for cpp test files from all tests
set(LIBS_TO_TEST "")   # i will
#==================================================================================================
#libs
add_subdirectory("./libs/")
#==================================================================================================
#app
add_subdirectory("./app/")
#==================================================================================================
#tests

#set(TEST_NAME "aizo_test")
#add_executable(${TEST_NAME} ${TEST_SOURCES})
#target_include_directories(${TEST_NAME} PUBLIC ${TEST_INCLUDES})

#target_link_libraries(${TEST_NAME} PUBLIC "stl_alter" Catch2::Catch2WithMain)
#enable_testing() #enables tests
#find_package(Catch2 REQUIRED)

#include(CTest)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
