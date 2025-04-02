cmake_minimum_required(VERSION 3.10)
project(lugui)

find_package(SDL3 REQUIRED)

add_executable(lugui src/lugui.cpp)
target_link_libraries(lugui PRIVATE SDL3::SDL3)
