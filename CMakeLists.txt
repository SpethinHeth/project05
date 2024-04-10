cmake_minimum_required(VERSION 3.0.0)
project(test_project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(test_project main.cpp)
target_sources(test_project PRIVATE "task.h" "task.cpp" "smartheap.h")
configure_file(p05input1.txt ${CMAKE_CURRENT_BINARY_DIR}/p05input1.txt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
