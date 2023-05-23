# Install script for directory: /home/soma1701/installations/hierarchies_to_scale/loop_fun_src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/soma1701/installations/my_stuff")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/soma1701/installations/my_stuff/lib/argos3" TYPE SHARED_LIBRARY FILES "/home/soma1701/installations/hierarchies_to_scale/loop_fun_src/build/libDDM_khepera_loop_function.so")
  if(EXISTS "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so"
         OLD_RPATH "/home/soma1701/installations/my_stuff/lib/argos3:/home/soma1701/installations/my_stuff/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/soft.computecanada.ca/gentoo/2020/usr/bin/strip" "$ENV{DESTDIR}/home/soma1701/installations/my_stuff/lib/argos3/libDDM_khepera_loop_function.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/soma1701/installations/hierarchies_to_scale/loop_fun_src/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
