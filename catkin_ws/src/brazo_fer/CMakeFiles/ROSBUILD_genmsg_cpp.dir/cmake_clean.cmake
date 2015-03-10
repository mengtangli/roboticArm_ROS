FILE(REMOVE_RECURSE
  "msg_gen"
  "msg_gen"
  "src/brazo_fer/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "msg_gen/cpp/include/brazo_fer/ReadServos.h"
  "msg_gen/cpp/include/brazo_fer/WriteServos.h"
  "msg_gen/cpp/include/brazo_fer/Servos.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
