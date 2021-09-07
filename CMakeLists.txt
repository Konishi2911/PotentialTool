cmake_minimum_required(VERSION 3.17)

project(pots CXX)
find_package(GTest REQUIRED)
enable_testing()


add_subdirectory(test)
add_subdirectory(src)
