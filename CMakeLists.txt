cmake_minimum_required(VERSION 3.0)

project(crazyCook)

# .cpp
file(GLOB SOURCES
    main.cpp
    src/*.cpp
)

find_package (SFML REQUIRED system window graphics audio)
# set(SFML_STATIC_LIBRARIES TRUE)

# Resources
file(GLOB TEXTURAS "resources/Imagenes/*")
file(COPY ${TEXTURAS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Imagenes) 

file(GLOB FUENTES "resources/Fuentes/*")
file(COPY ${FUENTES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Fuentes) 

file(GLOB TXT "*G.txt")
file(COPY ${TXT} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Texto) 

# Headers
include_directories(includes)

# Añade los source al ejecutable
add_executable (main ${SOURCES})

# Linkea las librerias al ejecutable
target_link_libraries(main sfml-system sfml-window sfml-graphics sfml-audio)
