project(application)

file(GLOB_RECURSE CPP_SRC *.cpp)
file(GLOB_RECURSE CPP_INC *.hpp)
file(GLOB_RECURSE UI_SRC *.ui)
file(GLOB_RECURSE RCC_SRC *.qrc)

qt5_wrap_ui(UI_CPP ${UI_SRC})

auto_source("${CPP_SRC};${CPP_INC};${UI_SRC};${RCC_SRC}")

add_executable(${PROJECT_NAME} WIN32 ${CPP_SRC} ${CPP_INC} ${UI_SRC} ${RCC_SRC} ${UI_CPP})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Network)

# Кириллица.
