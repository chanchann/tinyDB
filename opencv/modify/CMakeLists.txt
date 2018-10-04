cmake_minimum_required(VERSION 2.8)
project(modify)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(modify modify.cpp)
target_link_libraries(modify ${OpenCV_LIBS})

