cmake_minimum_required(VERSION 3.10)
project(MyC++Study)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files (경로 수정)
add_executable(MyApp
    include/rectangle/Rectangle.cpp  # 수정된 경로
    src/rectangle/rectangle1.cpp
)