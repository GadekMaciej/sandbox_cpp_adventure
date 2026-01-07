#pragma once

#include <chrono>
#include <functional>
#include <time/TimeUnitAliases.h>


/*
* not allow copying or moving
*/

/* Scoped timer using std::chrono*/
namespace olk::time
{
	template<typename time_unit_type = milliseconds>
	class scoped_timer
	{
	public:
		scoped_timer()
			: m_start_time_point(std::chrono::steady_clock::now())
		{}

		explicit scoped_timer(std::function<void(time_unit_type)> in_on_finish)
			: m_start_time_point(std::chrono::steady_clock::now()),
			m_on_finish_callback(std::move(in_on_finish))
		{}

		~scoped_timer()
		{
			if (m_on_finish_callback)
			{
				m_on_finish_callback(elapsed_time());
			}
		}

		[[nodiscard]] time_unit_type elapsed_time() const
		{
			return std::chrono::duration_cast<time_unit_type>(std::chrono::steady_clock::now() - m_start_time_point);
		}

	private:
		std::chrono::steady_clock::time_point m_start_time_point;
		std::function<void(time_unit_type)> m_on_finish_callback;
	};

	///* Helper function for creating scoped timer with label and units */
	//template <typename duration_type>
	//auto make_scoped_timer(std::string_view in_label, std::string_view in_unit)
	//{
	//	get_time_unit_suffix<int32_t>();
	//	return scoped_timer<duration_type>(
	//		[in_label, in_unit](duration_type elapsed_time)
	//		{
	//			std::cout << std::format("elapsed time: {}{} \n", in_label, elapsed_time.count());
	//		});
	//}
}