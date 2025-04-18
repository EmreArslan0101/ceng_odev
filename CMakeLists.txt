cmake_minimum_required(VERSION 3.16)
project(NotUygulamasi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)       
set(CMAKE_AUTOUIC ON)       
set(CMAKE_AUTORCC ON)       
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 REQUIRED COMPONENTS Widgets)
endif()

set(SOURCES
    src/*.cc
    libs/*.cc
    src/*.cpp
    libs/*.pp
)

set(HEADERS
    libs/*.h
)

set(UIS
    ui/*.ui
)

if(Qt6_FOUND)
    qt_wrap_ui(WRAPPED_UIS ${UIS}) 
    add_executable(NotUygulamasi ${SOURCES} ${HEADERS} ${UIS})
    target_link_libraries(NotUygulamasi Qt6::Widgets)
else()
    qt5_wrap_ui(WRAPPED_UIS ${UIS})
    add_executable(NotUygulamasi ${SOURCES} ${HEADERS} ${WRAPPED_UIS})
    target_link_libraries(NotUygulamasi Qt5::Widgets)
endif()
