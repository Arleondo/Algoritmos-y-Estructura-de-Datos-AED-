# CMakeList.txt: proyecto de CMake para Clase_AED_10-09, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (Clase_AED_10-09 "Clase_AED_10-09.cpp" "Clase_AED_10-09.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Clase_AED_10-09 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
