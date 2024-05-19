cmake_minimum_required(VERSION 3.16)
project(Bridge)


set(PROJECT_SOURCES
    bridge.cpp
)




add_library(project_lib STATIC ${PROJECT_SOURCES})


target_include_directories(project_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} project_lib)


enable_testing()
add_subdirectory(tests)
