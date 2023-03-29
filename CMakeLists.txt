cmake_minimum_required(VERSION 3.22)
project(Bag)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bag "App.cpp" "Bag.cpp" "Bag.h" "BagIterator.cpp" "BagIterator.h" "ShortTest.cpp" "ShortTest.h" "ExtendedTest.cpp" "ExtendedTest.h")
