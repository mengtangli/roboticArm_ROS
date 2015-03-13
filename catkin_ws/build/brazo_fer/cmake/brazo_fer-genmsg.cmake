# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "brazo_fer: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ibrazo_fer:/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(brazo_fer_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg" NAME_WE)
add_custom_target(_brazo_fer_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "brazo_fer" "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg" ""
)

get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg" NAME_WE)
add_custom_target(_brazo_fer_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "brazo_fer" "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg" "brazo_fer/Servos"
)

get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg" NAME_WE)
add_custom_target(_brazo_fer_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "brazo_fer" "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg" "brazo_fer/Servos"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/brazo_fer
)
_generate_msg_cpp(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg"
  "${MSG_I_FLAGS}"
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/brazo_fer
)
_generate_msg_cpp(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg"
  "${MSG_I_FLAGS}"
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/brazo_fer
)

### Generating Services

### Generating Module File
_generate_module_cpp(brazo_fer
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/brazo_fer
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(brazo_fer_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(brazo_fer_generate_messages brazo_fer_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_cpp _brazo_fer_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_cpp _brazo_fer_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_cpp _brazo_fer_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(brazo_fer_gencpp)
add_dependencies(brazo_fer_gencpp brazo_fer_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS brazo_fer_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/brazo_fer
)
_generate_msg_lisp(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg"
  "${MSG_I_FLAGS}"
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/brazo_fer
)
_generate_msg_lisp(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg"
  "${MSG_I_FLAGS}"
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/brazo_fer
)

### Generating Services

### Generating Module File
_generate_module_lisp(brazo_fer
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/brazo_fer
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(brazo_fer_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(brazo_fer_generate_messages brazo_fer_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_lisp _brazo_fer_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_lisp _brazo_fer_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_lisp _brazo_fer_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(brazo_fer_genlisp)
add_dependencies(brazo_fer_genlisp brazo_fer_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS brazo_fer_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer
)
_generate_msg_py(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg"
  "${MSG_I_FLAGS}"
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer
)
_generate_msg_py(brazo_fer
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg"
  "${MSG_I_FLAGS}"
  "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer
)

### Generating Services

### Generating Module File
_generate_module_py(brazo_fer
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(brazo_fer_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(brazo_fer_generate_messages brazo_fer_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/Servos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_py _brazo_fer_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/ReadServos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_py _brazo_fer_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/eeit/roboarm/catkin_ws/src/brazo_fer/msg/WriteServos.msg" NAME_WE)
add_dependencies(brazo_fer_generate_messages_py _brazo_fer_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(brazo_fer_genpy)
add_dependencies(brazo_fer_genpy brazo_fer_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS brazo_fer_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/brazo_fer)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/brazo_fer
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(brazo_fer_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(brazo_fer_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/brazo_fer)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/brazo_fer
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(brazo_fer_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(brazo_fer_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/brazo_fer
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(brazo_fer_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(brazo_fer_generate_messages_py std_msgs_generate_messages_py)
