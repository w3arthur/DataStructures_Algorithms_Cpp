# CMakeList.txt : CMake project for DataStructures_Algorithms_Cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (DataStructures_Algorithms_Cpp "DataStructures_Algorithms_Cpp.cpp" "DataStructures_Algorithms_Cpp.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DataStructures_Algorithms_Cpp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
