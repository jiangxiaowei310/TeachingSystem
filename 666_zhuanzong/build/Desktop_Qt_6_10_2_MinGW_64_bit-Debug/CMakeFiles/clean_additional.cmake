# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "666_zhuanzong_autogen"
  "CMakeFiles\\666_zhuanzong_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\666_zhuanzong_autogen.dir\\ParseCache.txt"
  )
endif()
