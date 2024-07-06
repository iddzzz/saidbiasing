cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(SaidBiasing)

find_package(Geant4 REQUIRED ui_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(saidbiasing saidbiasing.cc ${sources} ${headers})
target_link_libraries(saidbiasing ${Geant4_LIBRARIES})

add_custom_target(SaidBiasing DEPENDS saidbiasing)

set(saidbiasing_SCRIPTS
    vis.mac)
foreach(_script ${saidbiasing_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()