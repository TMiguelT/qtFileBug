cmake_minimum_required(VERSION 3.3)
project(QtTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0")
SET(CMAKE_C_FLAGS_DEBUG "-O0")

# Find the QtWidgets library
find_package(Qt5Widgets)

# Tell CMake to create the helloworld executable
add_executable(QtTest WIN32 main.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(QtTest Qt5::Widgets)

# Use the Widgets module from Qt 5.
target_link_libraries(QtTest Qt5::Widgets)

set(SOURCE_FILES main.cpp)