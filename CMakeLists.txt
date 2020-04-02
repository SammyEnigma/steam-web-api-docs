cmake_minimum_required(VERSION 3.14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(AUTOMOC_SOURCE_GROUP "Generated files\\")
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
#set(CMAKE_AUTOUIC ON)
# Create resources automatically.
set(CMAKE_AUTORCC ON)
# Add build directory to include paths in case of uic generated files.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Add custom cmake modules path.
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)


include(auto_source)
include(qt_auto_source)

project(steam-web-api-docs)

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Network)
#set(ENV{LUA_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/3psdk/lua53")
#find_package(Lua)

add_subdirectory(src)
add_subdirectory(deps/QHexView)
