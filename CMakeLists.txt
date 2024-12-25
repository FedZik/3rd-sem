cmake_minimum_required(VERSION 3.27)
project(3rd-sem)

set(CMAKE_CXX_STANDARD 17)

add_executable(3rd-sem demo/main.cpp
        domain/Client.cpp
        domain/Client.h
        domain/Manager.cpp
        domain/Manager.h
        domain/Property.cpp
        domain/Property.h
)
enable_testing()
add_subdirectory(googletest)

add_executable(3rd-sem12 tests/test.cpp
        tests/pch.cpp
        tests/pch.h)

target_link_libraries(3rd-sem12 gtest_main gmock_main)