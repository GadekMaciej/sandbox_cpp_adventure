// cpp_sample_span.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <span>
#include <vector>
#include "printing/PrintingHelpers.h"


int main()
{
	/*
	* why use std::span and what does it solve?
	* std::span is a lightweight view over a contiguous sequence of objects
	* instead of passing raw pointers and sizes around you can use std::span to provide a safer and more expressive interface
	* solving problems like:
	* 1. pointer can be null
	* 2. size can be incorrect
	* 3. pointer and size can be mismatched
	* 4. lack of information about ownership and lifetime of the data
	* 5. lack of information about mutability of the data
	* 6. no bounds safety
	* 7. no easy way to pass sub-ranges of data
	*
	* while providing benefits like:
	* 1. single parameter passing
	* 2. size always travels with pointer
	*/

	/* Old way */
	void process(int* in_data, std::size_t in_size);

	/* Since c++20 */
	void process(std::span<int32_t> in_data);

	std::vector<int32_t> data_vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::vector<std::vector<int32_t>> data_2d_vector = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};

	std::span<int32_t> data_span(data_vector);

	auto sub_span_3_6 = data_span.subspan(2, 5); // span over first 3 elements
	auto sub_span_first_5 = data_span.first(5);    // span over first 3 elements
	auto sub_span_last_4 = data_span.last(4);     // span over last 4 elements


	std::cout << olk::print::print_range(data_vector, "data vector") << olk::print::print_range(data_2d_vector);
}