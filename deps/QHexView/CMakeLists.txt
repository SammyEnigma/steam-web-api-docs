project(QHexView)

file(GLOB_RECURSE CPP_INC src/*.h src/*.hpp)
file(GLOB_RECURSE CPP_SRC src/*.cpp)

auto_source("${CPP_SRC};${CPP_INC}")

add_library(${PROJECT_NAME} STATIC ${CPP_SRC} ${CPP_INC})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)