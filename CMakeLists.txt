cmake_minimum_required(VERSION 3.10)
project(lugui)

find_package(SDL3 REQUIRED)

file(GLOB SOURCES "src/*.cpp" "src/drawables/*.cpp")

add_executable(lugui ${SOURCES})

target_link_libraries(lugui PRIVATE SDL3::SDL3)
target_include_directories(lugui PRIVATE src)
