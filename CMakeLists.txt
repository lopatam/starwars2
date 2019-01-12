cmake_minimum_required(VERSION 3.10)
project(starwars2)

set(CMAKE_CXX_STANDARD 17)

add_executable(example starwars2_example.cc rebelfleet.h battle.h imperialfleet.h)
