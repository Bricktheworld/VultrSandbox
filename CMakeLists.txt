cmake_minimum_required(VERSION 3.19.4)

set(This VultrDemo)

project(${This} VERSION 0.1.0)


enable_testing()

file(
  GLOB_RECURSE Sources
  "src/sources.cpp"
)

include_directories(src vendor vendor/VultrCore/src vendor/VultrCore/vendor)

if(UNIX)
  set(CMAKE_CXX_STANDARD 20)
endif(UNIX)

if(WIN32)
  add_compile_options("/std:c++latest")
  add_compile_options("/Zc:preprocessor")

  set(CMAKE_CXX_STANDARD 20)
endif(WIN32)


add_subdirectory(vendor/VultrCore)
add_library(${This} SHARED ${Sources})

set(TargetIncludeDirs src vendor)

set(Libs Vultr)

set_target_properties(Vultr PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${This} PUBLIC ${Libs})
target_include_directories(${This} PUBLIC ${TargetIncludeDirs})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

if(UNIX)
  set(CMAKE_CXX_FLAGS "-Wno-reorder -Wno-volatile -Wno-deprecated-enum-enum-conversion")
endif(UNIX)
