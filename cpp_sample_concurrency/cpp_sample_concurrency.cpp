// cpp_sample_concurrency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

void thread_print_func()
{
    std::cout << "Hello from thread!\n";
}

int main()
{
    /* There are two types of threads a regular thread and jthread which supports RAII in a sense that it joins/cleans itself up in destructor */
    std::thread thread_printer(&thread_print_func);
    std::jthread thread_jprinter(&thread_print_func);
	thread_printer.join();
    std::cout << "Hello from main thread!\n";
}

