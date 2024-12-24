cmake_minimum_required(VERSION 3.27)
project(3rd-sem)

set(CMAKE_CXX_STANDARD 17)

add_executable(3rd-sem demo/main.cpp
        domain/Exercise.cpp
        domain/Exercise.h
        domain/Generator.cpp
        domain/Generator.h
        domain/IStreamGenerator.cpp
        domain/IStreamGenerator.h
        domain/Matrix.cpp
        domain/Matrix.h
        domain/RandomGenerator.cpp
        domain/RandomGenerator.h
        domain/Task1.cpp
        domain/Task1.h
        domain/Task2.cpp
        domain/Task2.h)

enable_testing()
add_subdirectory(googletest)

add_executable(3rd-sem-tests tests/test.cpp
        tests/pch.cpp
        tests/pch.h)

target_link_libraries(3rd-sem-tests gtest_main gmock_main)