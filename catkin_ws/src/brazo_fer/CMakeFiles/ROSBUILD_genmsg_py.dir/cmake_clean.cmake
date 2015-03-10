FILE(REMOVE_RECURSE
  "msg_gen"
  "msg_gen"
  "src/brazo_fer/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "src/brazo_fer/msg/__init__.py"
  "src/brazo_fer/msg/_ReadServos.py"
  "src/brazo_fer/msg/_WriteServos.py"
  "src/brazo_fer/msg/_Servos.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
