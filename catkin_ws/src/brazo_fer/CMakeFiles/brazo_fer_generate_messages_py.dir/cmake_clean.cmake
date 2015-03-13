FILE(REMOVE_RECURSE
  "CMakeFiles/brazo_fer_generate_messages_py"
  "devel/lib/python2.7/dist-packages/brazo_fer/msg/_Servos.py"
  "devel/lib/python2.7/dist-packages/brazo_fer/msg/_ReadServos.py"
  "devel/lib/python2.7/dist-packages/brazo_fer/msg/_WriteServos.py"
  "devel/lib/python2.7/dist-packages/brazo_fer/msg/__init__.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/brazo_fer_generate_messages_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
