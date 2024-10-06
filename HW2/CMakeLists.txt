cmake_minimum_required(VERSION 3.5)

project(HW2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)  # C++ 표준 버전을 14로 올림
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(X11 REQUIRED)  # X11 라이브러리 추가
find_package(PkgConfig REQUIRED)  # PkgConfig 사용 준비
pkg_check_modules(X11_XTEST REQUIRED xtst)  # Xtst 라이브러리 추가

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(HW2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(HW2 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(HW2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Xtst 라이브러리를 X11과 함께 링크
target_link_libraries(HW2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets X11::X11 ${X11_XTEST_LIBRARIES})

set_target_properties(HW2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HW2)
endif()
