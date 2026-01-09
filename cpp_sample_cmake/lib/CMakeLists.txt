add_library(cpp_sample_cmake_library)

target_sources(cpp_sample_cmake_library
	PRIVATE
		cpp_sample_cmake_library.cpp

	PUBLIC
		FILE_SET myHeaders
		TYPE HEADERS
		FILES
			cpp_sample_cmake_library.h
)

target_compile_features(cpp_sample_cmake_library PRIVATE cxx_std_20)

if(TUTORIAL_USE_STD_SQRT)
  target_compile_definitions(cpp_sample_cmake_library PRIVATE TUTORIAL_USE_STD_SQRT)
endif()