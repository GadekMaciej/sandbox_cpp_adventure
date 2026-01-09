add_executable(cpp_sample_cmake)

target_sources(cpp_sample_cmake 
PRIVATE 
	cpp_sample_cmake.cpp
)

target_link_libraries(cpp_sample_cmake
	PRIVATE
		cpp_sample_cmake_library
)

target_compile_features(cpp_sample_cmake PRIVATE cxx_std_20)