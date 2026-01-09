#pragma once

#include <vector>
#include <format>
#include "concepts/Concepts.h"

namespace olk::print
{
	/* TODO: support for recursive ranges */
	template<std::ranges::input_range range_type>
	//requires olk::concepts::formattable<std::ranges::range_value_t<range_type>>
	std::string print_range(
		range_type&& in_range,
		std::string_view in_label = "Vector", 
		std::string_view in_delimiter = ", ", 
		std::string_view in_prefix = "[", 
		std::string_view in_postfix = "]")
	{
		std::string result;

		// if the range is "sized"
		if constexpr (std::ranges::sized_range<range_type>)
		{
			constexpr size_t avg_chars_per_element = 8;
			result.reserve(
				in_label.size()
				+ in_prefix.size()
				+ in_postfix.size()
				+ std::ranges::size(in_range) * avg_chars_per_element
			);
		}

		auto result_back_insert_ptr = std::back_inserter(result);
		std::format_to(result_back_insert_ptr, "{}: {}", in_label, in_prefix);

		bool first = true;
		for (const auto& element : in_range)
		{
			if (!first)
			{
				std::format_to(result_back_insert_ptr, "{}", in_delimiter);
			}

			first = false;
			std::format_to(result_back_insert_ptr, "{}", element);
		}

		std::format_to(result_back_insert_ptr, "{}", in_postfix);
		return result;
	}


}