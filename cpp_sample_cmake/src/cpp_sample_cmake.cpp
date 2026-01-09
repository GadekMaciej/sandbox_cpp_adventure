// A simple program that computes the square root of a number


#include <iostream>
#include <format>
#include <string>

#include <cpp_sample_cmake_library.h>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << std::format("Usage: {} number\n", argv[0]);
		return 1;
	}

	// convert input to double
	double const inputValue = std::stod(argv[1]);

	// calculate square root
	double const outputValue = cpp_library::sqrt(inputValue);

	std::cout << std::format("The square root of {} is {}\n", inputValue,
		outputValue);
}
