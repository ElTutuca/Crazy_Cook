cmake_minimum_required(VERSION 3.0)

project(crazyCook)

# .cpp
file(GLOB SOURCES
    main.cpp
    src/*.cpp
)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake-modules/")
find_package (SFML REQUIRED system window graphics audio)

# Headers
include_directories(${SFML_INCLUDE_DIR} includes)

# Añade los source al ejecutable
add_executable (main ${SOURCES})

# Linkea las librerias al ejecutable
target_link_libraries(main sfml-system sfml-window sfml-graphics sfml-audio)