cmake_minimum_required(VERSION 2.8.3)
project(sub_pub)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## Declare a catkin package
catkin_package()

## Build nodes
include_directories(include ${catkin_INCLUDE_DIRS})

#add_dependencies(${sub_pub} ${${sub_pub}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Publisher Node
add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})

## Subscriber Node
add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})



