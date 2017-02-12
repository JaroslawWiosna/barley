cmake_minimum_required(VERSION 2.8)
 
PROJECT(Barley)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(Barley ReadSTL)
 
if(VTK_LIBRARIES)
  target_link_libraries(Barley ${VTK_LIBRARIES})
else()
  target_link_libraries(Barley vtkHybrid vtkWidgets)
endif()
