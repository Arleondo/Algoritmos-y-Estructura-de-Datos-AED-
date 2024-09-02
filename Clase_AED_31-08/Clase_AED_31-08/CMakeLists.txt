# CMakeList.txt: proyecto de CMake para Clase_AED_31-08, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (Clase_AED_31-08 "Clase_AED_31-08.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Clase_AED_31-08 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
