cmake_minimum_required(VERSION 3.25)
project(triangles)

set(CMAKE_CXX_STANDARD 17)

add_executable(triangles main.cpp
        "geometry.cpp"
        "search.cpp"
        "file.cpp")
