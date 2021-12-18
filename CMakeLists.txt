cmake_minimum_required(VERSION 3.19.4)

set(This VultrDemo)

project(${This} VERSION 0.1.0)


enable_testing()

file(
  GLOB_RECURSE Sources
  # "vendor/*.cpp"
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
  add_subdirectory(vendor/VultrCore)
endif(WIN32)


add_library(${This} SHARED ${Sources})

set(TargetIncludeDirs src vendor)

if(WIN32)
  set(Libs Vultr)
endif(WIN32)

target_link_libraries(${This} PUBLIC ${Libs})
target_include_directories(${This} PUBLIC ${TargetIncludeDirs})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

if(UNIX)
    set(CMAKE_CXX_FLAGS "-Wno-reorder -Wno-volatile -Wno-deprecated-enum-enum-conversion")
endif(UNIX)
