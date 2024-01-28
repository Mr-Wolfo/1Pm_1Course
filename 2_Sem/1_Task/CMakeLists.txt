cmake_minimum_required(VERSION 3.25)

set (PROJECT_NAME 1_Task)
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)

include_directories("inc")

add_executable("${PROJECT_NAME}" main.cpp inc/Func.h src/Func.cpp)

file(COPY "StartTime.txt" DESTINATION "/")