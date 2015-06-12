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
  INCLUDE_DIRS include
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

add_executable(arm_test src/arm_test.cpp src/arm_control.cpp)
target_link_libraries(arm_test ${catkin_LIBRARIES})
add_dependencies(arm_test arm_control_generate_messages_cpp)
