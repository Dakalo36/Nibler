cmake_minimum_required(VERSION 3.7)
project(Nibbler_Final)

set(CMAKE_CXX_STANDARD 11)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})



set(SOURCE_FILES CoreSource/main.cpp CoreSource/Snake.cpp CoreSource/SnakePosition.cpp)
add_executable(Nibbler_Final ${SOURCE_FILES})
target_link_libraries(Nibbler_Final ${CURSES_LIBRARIES})
