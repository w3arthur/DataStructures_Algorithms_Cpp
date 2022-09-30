# CMakeList.txt : CMake project for DataStructures_Algorithms_Cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable ("CMakeExample" "CmakeExample.cpp" "CmakeExample.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeExample PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
# install (TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMACK_INSTALL_PREFIX}/bin
# install (FILES "Main.cpp" DESTINATION src) #${CMACK_INSTALL_PREFIX}/src