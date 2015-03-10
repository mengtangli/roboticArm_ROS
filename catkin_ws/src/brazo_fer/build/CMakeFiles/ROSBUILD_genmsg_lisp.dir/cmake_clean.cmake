FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/brazo_fer/msg"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/ReadServos.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_ReadServos.lisp"
  "../msg_gen/lisp/WriteServos.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_WriteServos.lisp"
  "../msg_gen/lisp/Servos.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_Servos.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
