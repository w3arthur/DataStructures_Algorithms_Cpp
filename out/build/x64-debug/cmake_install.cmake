# Install script for directory: C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/install/x64-debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/CMakeExample/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/1_1_ArrayList/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/1_2_LinkedList/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/1_3_Stack/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/1_4_Queue/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/1_5_Hashtable/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/2_1_BinaryTree/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/2_2_AVLTree/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/2_3_HeapTree/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/2_4_TrieTree/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/2_5_Graph/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/2_6_GraphUndirected/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/3_1_Searching/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/3_2_Sorting/cmake_install.cmake")
  include("C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/3_3_String/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/pc1/Desktop/DataStructure_Backup/DataStructures_Algorithms_Cpp/out/build/x64-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
