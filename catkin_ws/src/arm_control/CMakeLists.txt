cmake_minimum_required(VERSION 2.8.3)
project(arm_control)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	message_generation
	genmsg
)

add_message_files(
	FILES
	num.msg
	servo.msg
)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_tut
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
   CATKIN_DEPENDS message_runtime
)

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pub1 src/pub1.cpp)
target_link_libraries(pub1 ${catkin_LIBRARIES})
add_dependencies(pub1 arm_control_generate_messages_cpp)
