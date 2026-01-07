// cpp_sample_ranges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
 
/* 
* This is a sample of c++ ranges 
* TODO
* cyclic iterator
* iterating over multiple ranges inside one loop
*/

int main()
{
    /* Iterator way: */
    std::vector<int32_t> int_Array{ 1, 122, 112, -300, 75, 86, 36, -5};

    std::cout << "Unsorted array: \n";
    for (int32_t i : int_Array)
    {
        std::cout << i << ", ";
    }

    std::cout << "\n\n";

    /* Sorting an array */
    std::sort(int_Array.begin(), int_Array.end());

    std::cout << "Sorted array: \n";
    for (int32_t i : int_Array)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n\n";

    /* 
    * Ranges way:
    * 
    * Relevant namespaces are
    * std::ranges;
    * std::ranges::views;
    * std::views;           which is an abbreviation of above
    */

    /* Ranges way of filtering even numbers */
    auto filter_Result = int_Array | std::views::filter([](int32_t i) { return i % 2 == 0; });
    std::cout << "Filtered even numbers only: \n";
    for (int32_t i : filter_Result)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n\n";

    /* 
    * Ranges use pipe operator, which can be chained like below
    * They are also lazily evalueated, which means that below variable is only a set of instructions and a pointer to data
    * the actual work is being done when the value is requested by the for range loop below that prints the range
    */
    auto filter_And_Transform_Result = int_Array
        | std::ranges::views::filter([](int32_t i) { return i % 2 == 0; })  // take only the even numbers
        | std::ranges::views::transform([](int32_t i) { return i * 2;  });  // multiply by 2

    std::cout << "Filtered 0dd numbers only, then multiplied by 2: \n";
    for (int32_t i : filter_And_Transform_Result)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n\n";

    auto first_24_Numbers_View =
        std::ranges::views::iota(0, 24)     // take numbers 0, 1, 2, ... 23
        | std::ranges::views::transform([](int32_t a) { return std::make_unique<int32_t>(a); });
        /*| std::ranges::views::take(24);   // this would work equiavalently as not specifying second argument for iota "24" */

    /* Constructing a vector from  */
    std::vector<std::unique_ptr<int32_t>> vector_Of_24_Numbers(first_24_Numbers_View.begin(), first_24_Numbers_View.end());

    for (auto& i : vector_Of_24_Numbers)
    {
        std::cout << *i << ", ";
    }
    std::cout << "\n\n";
}