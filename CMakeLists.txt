cmake_minimum_required(VERSION 3.10)

project(dummy_project)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV CONFIG REQUIRED)

message(STATUS "INCLUDE DIRS ${OpenCV_INCLUDE_DIRS}")

message(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")

add_executable(camcap src/main.cpp)

target_link_libraries(camcap PRIVATE opencv_core opencv_imgcodecs opencv_highgui opencv_videoio)
