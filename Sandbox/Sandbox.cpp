// Sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>

#include <vector>
#include <array>

#include <time/ScopedTimer.h>
#include <time/TimeUnitAliases.h>

namespace Multithreading_Constants
{
    constexpr long buffer_Size = 50000;
}

int main()
{
    olk::time::scoped_timer<olk::time::seconds_double> timer([](olk::time::seconds_double elapsed_Time)
        {
            std::cout << "Elapsed time: " << elapsed_Time.count() << " ms\n";
		});

    std::random_device random_Device;
    std::mt19937 mersenne_Twister_Engine(random_Device());
    std::uniform_int_distribution<int32_t> random_Int_0_127(0, 127);

    std::vector<std::array<int32_t, Multithreading_Constants::buffer_Size>> data_Array(4);

    for (auto& arr : data_Array)
    {
        std::ranges::generate(arr, []() { return 9; });
    }

    //for (auto& arr : data_Array)
    //{
    //    std::ranges::generate(arr, []() { return olk::random::dice<0>; });
    //}
}