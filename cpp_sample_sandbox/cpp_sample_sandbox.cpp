// cpp_sample_sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <format>
#include <type_traits>
#include <concepts>
#include <string>

struct not_formattable_type 
{
    int32_t data;
};

template <typename T, typename CharT = char>
concept has_std_formatter =
    requires {
    typename std::formatter<T, CharT>;
};

template <typename T, typename CharT = char>
concept std_formattable =
    requires(const T & t,
std::basic_format_context<
    std::back_insert_iterator<std::basic_string<CharT>>, CharT> ctx,
    std::formatter<T, CharT> fmt)
{
    fmt.format(t, ctx);
};

template <typename T, typename OutIt, typename CharT = char>
concept std_formattable_to = requires(const T & t, OutIt out) {
    { std::format_to(out, std::declval<const CharT*>(), t) }
    -> std::same_as<OutIt>;
};

template <typename T>
requires std_formattable<T>
void test_formatting(const T & value) 
{
    std::string result = std::format("Formatted value: {}", value);
}

int main() {
    //not_formattable_type klocek;
    //test_formatting(klocek);
    ////static_assert(std_formattable<not_formattable_type>);          // OK
    //static_assert(std_formattable<std::string>);  // OK
}