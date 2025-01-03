cmake_minimum_required(VERSION 3.31.1) # min required vers of cmake.
set(PROJECT_NAME file_compresser) # project name & executable name
set(SOURCE_FILES src/main.c)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
