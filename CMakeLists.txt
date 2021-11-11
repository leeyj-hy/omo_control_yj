cmake_minimum_required(VERSION 3.0.2)
project(omo_control)

find_package(catkin REQUIRED COMPONENTS
  fiducial_msgs
  geometry_msgs
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES omo_control
#  CATKIN_DEPENDS fiducial_msgs geometry_msgs roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/omo_control.cpp
# )

add_executable(omo_control_pub src/omo_control_pub.cpp)
add_dependencies(omo_control_pub ${${PROJECT_NAME}_EXPORTED_TARGETS}
                 ${catkin_EXPORTED_TARGETS})
target_link_libraries(omo_control_pub
  ${catkin_LIBRARIES}
)

