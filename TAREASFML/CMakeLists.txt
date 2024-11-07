cmake_minimum_required(VERSION 3.28)
project(TAREASFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(TAREASFML main.cpp)

include_directories(headers /usr/include c:SFML/include)

# Especifica la ruta a SFML
set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# Encuentra las librerías de SFML
find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)

if (SFML_FOUND)
    # Vincula SFML con tu proyecto
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TAREASFML sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
endif ()

IF (WIN64)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
ENDIF ()