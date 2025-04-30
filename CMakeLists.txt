cmake_minimum_required(VERSION 3.13)
project(graphic)

add_executable(graphic source/main.cpp)
add_subdirectory(lib/glad)
target_link_libraries(graphic glad)
add_subdirectory(lib/glfw-3.4)
target_link_libraries(graphic glfw)



