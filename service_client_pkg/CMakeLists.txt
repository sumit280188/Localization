cmake_minimum_required(VERSION 2.8.3)
project(service_client_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation  # If you have message dependencies
)

# Add service files
add_service_files(
  FILES
  AddTwoInts.srv
)

# Generate added messages and services
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs message_runtime
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(service src/service.cpp)
add_executable(client src/client.cpp)

target_include_directories(client PUBLIC ${catkin_INCLUDE_DIRS})

add_dependencies(service service_client_pkg_generate_messages_cpp)
add_dependencies(client service_client_pkg_generate_messages_cpp)

#add_dependencies(service ${service_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#add_dependencies(client ${client_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(service ${catkin_LIBRARIES})
target_link_libraries(client ${catkin_LIBRARIES})
