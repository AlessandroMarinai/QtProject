cmake_minimum_required(VERSION 3.14)
project(ActivityRegister)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.12.3/lib/cmake/")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_subdirectory(test)

set(SOURCE_FILES Date.h Time.h Date.cpp Activity.h)
add_executable(ActivityRegister main.cpp MainDialog.h MainDialog.cpp Activity.h Register.h Date.h Time.h Date.cpp AddNewActivityDialog.cpp AddNewActivityDialog.h SavedOrNotDialog.h SavedOrNotDialog.cpp EventsDisplayerDialog.cpp EventsDisplayerDialog.h Register.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(ActivityRegister Qt5::Widgets)



