cmake_minimum_required(VERSION 3.22)

project("String value" VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_subdirectory(src)

target_link_libraries(correct_string PRIVATE Qt6::Core Qt6::Widgets)

set_target_properties(correct_string PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

install(TARGETS correct_string
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
