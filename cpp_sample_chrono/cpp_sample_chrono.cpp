#include <iostream>
#include <chrono>
#include <thread>


// This is a chrono library sample.

// TODO:
// 1. It is easy to inspect duration class and get to know exactly what it represents, what its underlying type is as well as its period.
// 2. round and ceil examples


/*
* Required for user defined literals e.g.
* std::chrono::seconds six_Seconds = 6s;
* instead of:
* std::chrono::seconds six_Seconds = std::chrono::seconds{6};
*/
using namespace std::chrono_literals;

int main()
{
    /* 
    * Duration representation 
    * Chrono uses time units: seconds, minutes and hours.
    */
    std::chrono::seconds six_Seconds = std::chrono::seconds{6};
    /* Using user defined literals */
    std::chrono::seconds one_Second                 = 1s;
    std::chrono::minutes one_Minute                 = 1min;
    std::chrono::milliseconds twelve_Milliseconds   = 12ms;
    std::chrono::hours day                          = 24h;

    /* Lossless conversions can and should stay implicit */
    std::chrono::hours eighteen_Hours               = 18h;
    std::chrono::milliseconds play_Session_Duration = eighteen_Hours;

    /* Lossy conversions need duration_cast<>() */
    std::chrono::seconds fifty_Seconds              = 50s;
    std::chrono::minutes travel_Duration            = std::chrono::duration_cast<std::chrono::minutes>(fifty_Seconds);

    /* User defined duration */
    using my_Custom_Second_Type =   std::chrono::duration<long long, std::ratio<1, 1>>;
    using half_A_Second_Type =      std::chrono::duration<long long, std::ratio<1, 2>>;
    using an_hour_and_a_Half_Type = std::chrono::duration<long long, std::ratio<5400, 1>>;
    /* More verbose alternative to above */
    using also_An_hour_and_a_Half_Type = std::chrono::duration<long long, std::ratio_multiply<std::ratio<60, 1>, std::ratio<90, 1>>>;


    /* Underlying type may be changed if you don't need it to be long long (which is by default) */
    using frame_Duration =          std::chrono::duration<int32_t, std::ratio<1, 60>>;

    /* 
	* When comparing two ratios prefer former. is_same is stricter as it checks for both period and underlying type.
    */
	bool b_is_same_duration_type = std::ratio_equal<an_hour_and_a_Half_Type::period, also_An_hour_and_a_Half_Type::period>::value;
	bool b_is_same_duration_type_2 = std::is_same<an_hour_and_a_Half_Type, also_An_hour_and_a_Half_Type>::value;


    /*
    * Time point representation
    * Use steady clock for measuring time - think your regular stopwatch
    * Use system clock for anything that involves dates - logging system
    * High resolution clock is just a typedef for one of above, which in particular is up to system implementation
    * There exist additional clocks added in c++20 which are not covered here.
    */
    std::chrono::steady_clock::time_point now_Steady = std::chrono::steady_clock::now();
    std::chrono::system_clock::time_point now_System = std::chrono::system_clock::now();
    std::chrono::steady_clock::time_point now_High_Resolution = std::chrono::high_resolution_clock::now();

    /* How many frames since epoch */
    frame_Duration duration_Since_Epoch = std::chrono::duration_cast<frame_Duration>(std::chrono::steady_clock::now().time_since_epoch());

    /* Display current date but round to 30 minutes */

    using seconds_In_Minute =       std::ratio<60, 1>;
    using minutes_In_Half_An_Hour = std::ratio<30, 1>;
    using seconds_In_Half_An_Hour = std::ratio_multiply<seconds_In_Minute, minutes_In_Half_An_Hour>;
    using half_An_Hour_Type =       std::chrono::duration<int32_t, seconds_In_Half_An_Hour>;

    std::chrono::system_clock::time_point current_Time_Rounded = std::chrono::floor<half_An_Hour_Type>(std::chrono::system_clock::now());
}