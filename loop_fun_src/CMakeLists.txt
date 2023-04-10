cmake_minimum_required(VERSION 2.8.12)
project(DDM_khepera_loop_function)
set(CMAKE_CXX_STANDARD 11)
# Deactivate RPATH for MacOSX
set(CMAKE_MACOSX_RPATH 0)

# Find the ARGoS package
find_package(PkgConfig REQUIRED)
find_package(ARGoS REQUIRED)


include_directories(${ARGOS_INCLUDE_DIRS})
link_directories(${ARGOS_LIBRARY_DIR})
link_libraries(${ARGOS_LDFLAGS})
string(REPLACE "/lib/argos3" "" ARGOS_PREFIX "${ARGOS_LIBRARY_DIR}")
set(CMAKE_INSTALL_PREFIX ${ARGOS_PREFIX} CACHE STRING "Install path prefix, prepended onto install directories." FORCE)


# Find the Buzz package
find_package(PkgConfig)
pkg_check_modules(BUZZ REQUIRED buzz)

include_directories(${CMAKE_SOURCE_DIR} ${ARGOS_INCLUDE_DIRS} ${BUZZ_INCLUDE_DIR} )

find_package(Lua52)
if(Lua52_FOUND)
  include_directories(${LUA_INCLUDE_DIR})
endif(Lua52_FOUND)


# Set ARGoS link dir
link_directories(${ARGOS_LIBRARY_DIRS} ${BUZZ_LIBRARY_DIRS})

# Compile target
add_library(DDM_khepera_loop_function SHARED DDM_khepera_loop_function.h buzz_utils.h DDM_khepera_loop_function.cpp)
target_link_libraries(DDM_khepera_loop_function
  buzz
  argos3core_simulator
  argos3plugin_simulator_dynamics2d
  argos3plugin_simulator_entities
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot
  argos3plugin_simulator_media
  argos3plugin_simulator_buzz
  )



# Install stuff
install(TARGETS DDM_khepera_loop_function DESTINATION ${ARGOS_PREFIX}/lib/argos3)