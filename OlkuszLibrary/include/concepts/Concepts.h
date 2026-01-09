#pragma once

#include <concepts>
#include <format>

namespace olk::concepts
{
	///* Concept checking if a type is formattable via std::format */
	//template<typename formattable_type, typename char_type = char>
	//concept formattable = requires { typename std::formatter<formattable_type, char_type>; };

	//template<typename T>
	//concept Formattable = requires(T t) 
	//{
	//	{ std::format("{}", t) } -> std::convertible_to<std::string>;
	//};

	//template<typename T>
	//concept formattable = requires (T & v, std::format_context ctx) {
	//	std::formatter<std::remove_cvref_t<T>>().format(v, ctx);
	//};

	//template<typename T>
	//concept formattable = requires (T & v, std::format_context ctx) {
	//	std::formatter<std::remove_cvref_t<T>>().format(v, ctx);
	//};







	template<typename formatter_policy_type>
	concept formatter_policy = requires(
		formatter_policy_type formatter_policy_value,
		std::string& out,
		std::string_view label)
	{
		// range structure
		{ formatter_policy_type::prefix() } -> std::convertible_to<std::string_view>;
		{ formatter_policy_type::postfix() } -> std::convertible_to<std::string_view>;
		{ formatter_policy_type::delimiter() } -> std::convertible_to<std::string_view>;

		// label formatting
		{ formatter_policy_value.format_label(out, label) };

		// base element formatting
		{ formatter_policy_value.format_value(out, std::declval<int>()) };
	};

	struct DefaultPolicy
	{
		static constexpr std::string_view prefix() { return "["; }
		static constexpr std::string_view postfix() { return "]"; }
		static constexpr std::string_view delimiter() { return ", "; }

		void format_label(std::string& out, std::string_view label) const
		{
			std::format_to(std::back_inserter(out), "{}: ", label);
		}

		template<typename T>
			requires formattable<T>
		void format_value(std::string& out, const T& value) const
		{
			std::format_to(std::back_inserter(out), "{}", value);
		}
	};
}
