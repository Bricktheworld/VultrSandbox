cmake_minimum_required(VERSION 3.19.4)

set(This Gameplay)

project(${This} VERSION 0.1.0)


enable_testing()

file(
        GLOB_RECURSE Sources
        "src/sources.cpp"
)

include_directories(src vendor vendor/VultrCore/src vendor/VultrCore/vendor)


if (WIN32)
    add_compile_options("/std:c++latest")
    add_compile_options("/Zc:preprocessor")
endif (WIN32)

set(CMAKE_CXX_STANDARD 20)
add_compile_options("-Wno-reorder" "-Wno-deprecated-enum-enum-conversion" "-Wgnu-array-member-paren-init")


add_subdirectory(vendor/VultrCore)
add_library(${This} SHARED ${Sources})

set(TargetIncludeDirs src vendor)

set(Libs Vultr)

set_target_properties(Vultr PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${This} PUBLIC ${Libs})
target_include_directories(${This} PUBLIC ${TargetIncludeDirs})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -ftime-trace")
