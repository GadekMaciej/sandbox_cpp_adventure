cmake_minimum_required(VERSION 3.23)

project(cpp_sample_cmake_project)

option(TUTORIAL_BUILD_UTILITIES "Whether only math library should be built" ON)
option(TUTORIAL_USE_STD_SQRT " use std::sqrt" OFF)

if (${TUTORIAL_BUILD_UTILITIES})
	add_subdirectory(src)
endif()

add_subdirectory(lib)

# for commenting single line

#[[
	for multi line comments
]]


