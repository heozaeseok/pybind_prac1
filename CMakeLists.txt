cmake_minimum_required(VERSION 3.15)
project(pybind_prac)

set(CMAKE_CXX_STANDARD 17)

# Python 찾기 (자동으로 include / lib 설정)
find_package(Python REQUIRED COMPONENTS Interpreter Development)

# pybind11 submodule 추가
add_subdirectory(external/pybind11)

# 실행파일 생성 - build 한 번하고 실행파일 여러개 가능함
add_executable(main main.cpp)
add_executable(main2 main2.cpp)

# pybind11 + Python 자동 링크 -> 실행할 cpp 파일 다 추가해야함
target_link_libraries(main PRIVATE pybind11::embed)
target_link_libraries(main2 PRIVATE pybind11::embed)
