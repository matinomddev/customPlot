# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\customPlotProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\customPlotProject_autogen.dir\\ParseCache.txt"
  "customPlotProject_autogen"
  )
endif()
