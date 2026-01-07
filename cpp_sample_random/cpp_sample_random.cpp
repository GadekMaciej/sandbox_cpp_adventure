// cpp_sample_random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

/* 
 * This is a sample of randomization in C and C++ 
 * TODO:
 * provide a shuffle example using std
 * min std rand as a more compact alternative to mersenne twister
 * PCG random generator - even better than mt19937 supposedly
 */

int main()
{

    /* 
    * C style of randomization
    * Provide a seed for rand(), if you ommit this step rand() will produce the same result every time. 
    * Pros:
    * 1. It is easy to set up
    * Cons:
    * 1. rand() provides value between 0 and MAX_RAND. If you want different range easiest way is to use modulo operator.
    * 2. Modulo operator makes the results of rand() non uniform, meaning some values are more likely to show up.
    * 3. A fix to this would be Rejection sampling, but it requires additional computation which is not ideal
    * 4. Uses linear congruential generator which makes low bit predictable in some situations
    */
    srand((unsigned)time(NULL));
    int32_t c_Rand_Random_Number = rand();

    /* 
    * BAD:
    * Say we need a random number between 0 and 19
    */
    int32_t random_Number_Between_0_And_19 = rand() % 20;

    /* 
    * The reason why above is bad:
    * 32767 % 20 == 7, which means 0 to 7 results are slightly more probable
    * To prevet that the upper limit has to be truncated
    */

    /* Rejection sampling example: */
    int32_t new_Limit = RAND_MAX - (RAND_MAX % 20);
    random_Number_Between_0_And_19 = rand();

    while (random_Number_Between_0_And_19 >= new_Limit)
    {
        random_Number_Between_0_And_19 = rand();
    }

    random_Number_Between_0_And_19 = random_Number_Between_0_And_19 % 20;

    /*
    * C++ style of randomization
    * provide a seed for random engine (engine that provide random bits)
    * Instantiate a distribution you are interested in this example it will be the most common and widely used uniform int distribution
    * Finally to get the random number feed the random engine into the distribution
    */

    int32_t some_Random_Seed = 1337;
    std::mt19937 mersenne_Twister_Fixed_Seed(some_Random_Seed);
    std::uniform_int_distribution<int> inclusive_1_To_20(1, 20);
    int32_t random_Number_Between_1_And_20 = inclusive_1_To_20(mersenne_Twister_Fixed_Seed);

    /* 
    * For nondeterministic behavior every time the program starts you can seed the mersenne twister with a random number from random_device.
	* random_device is a non-deterministic random number generator, it is supposed to provide true random numbers in form of unsigned integers (presumably uint32_t) from hardware
    * The question arises why not just use random_device to begin with? There are multiple reasons:
    * 1. it requires way more cpu cycles
    * 2. it is system/hardware specific
    * 3. it is not seedable
    * 
    * But it is not all bad, while mersenne twister is way faster, it is not cryptographically secure in contrast to random_device which can be cryptographically secure (but is not guaranteed to be).
    */
    std::random_device random_Device;
    std::mt19937 mersenne_Twister_Random_Seed(random_Device());
    /* 
    * In fact mersenne twister has enormous internal state, around 624 * 32 bits, providing more entropy causes the results to be even better.
    * Dont bother providing more than 8 or 16 * 32 bits, OS might run out of entropy and cause random_Device() to throw.
    */
    std::seed_seq seed_Sequence
    {
        random_Device(), random_Device(), random_Device(), random_Device(),
        random_Device(), random_Device(), random_Device(), random_Device()
    };

    std::mt19937 mersenne_Twister_Random_Seed_Even_Better(seed_Sequence);

    std::cout << "Max random % 20: " << RAND_MAX % 20 << "\n\n";
    std::cout << "Random numbers: " << "\n C - rand(): " << c_Rand_Random_Number;
}
