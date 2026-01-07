#pragma once

#include <chrono>
/* File containing aliases for common time units */

namespace olk::time
{
	using hours					= std::chrono::hours;
	using hours_double			= std::chrono::duration<double, std::ratio<3600, 1>>;

	using minutes				= std::chrono::minutes;
	using minutes_double		= std::chrono::duration<double, std::ratio<60, 1>>;

	using seconds				= std::chrono::seconds;
	using seconds_double		= std::chrono::duration<double, std::ratio<1, 1>>;

	using milliseconds			= std::chrono::milliseconds;
	using milliseconds_double	= std::chrono::duration<double, std::ratio<1, 1000>>;

	using microseconds			= std::chrono::microseconds;
	using microseconds_double	= std::chrono::duration<double, std::ratio<1, 1000000>>;

	using nanoseconds			= std::chrono::nanoseconds;
	using nanoseconds_double	= std::chrono::duration<double, std::ratio<1, 1000000000>>;

	/* make tests for if this works properly */
	//template<typename duration_type>
	//constexpr std::string_view get_time_unit_suffix()
	//{
	//	if constexpr (std::ratio_equal_v<duration_type::period, hours>)
	//	{
	//		return "h";
	//	}
	//	else if constexpr (std::ratio_equal_v<duration_type::period, minutes>)
	//	{
	//		return "min";
	//	}
	//	else if constexpr (std::ratio_equal_v<duration_type::period, seconds>)
	//	{
	//		return "s";
	//	}
	//	else if constexpr (std::ratio_equal_v<duration_type::period, milliseconds>)
	//	{
	//		return "ms";
	//	}
	//	else if constexpr (std::ratio_equal_v<duration_type::period, microseconds>)
	//	{
	//		return "us";
	//	}
	//	else if constexpr (std::ratio_equal_v<duration_type::period, nanoseconds>)
	//	{
	//		return "ns";
	//	}
	//	else
	//	{
	//		return "unknown unit";
	//	}
	//}
}