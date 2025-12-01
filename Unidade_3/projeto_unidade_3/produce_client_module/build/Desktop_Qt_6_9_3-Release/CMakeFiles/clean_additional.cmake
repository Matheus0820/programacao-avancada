# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/produce_client_module_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/produce_client_module_autogen.dir/ParseCache.txt"
  "produce_client_module_autogen"
  )
endif()
