#CMakeLists for main executable of main project

#main app executable
set(APP_SOURCES "main.cpp")
add_executable(${PROJECT_NAME} ${APP_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC "stl_alter")
#tests for app
add_subdirectory("./tests/")
set(TEST_SOURCES ${TEST_SOURCES} PARENT_SCOPE})
