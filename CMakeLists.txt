cmake_minimum_required(VERSION 3.16)

project(aizo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES)   #for sources from all tests
#==================================================================================================
#libs
add_subdirectory("./libs/")
#==================================================================================================
#app
add_subdirectory("./app/")
#==================================================================================================
#tests


include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
