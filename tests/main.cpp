#include <iostream>
#include <iomanip>
#include <string>
#include <cpptest/cpptest.h>

void print_ruller(size_t length, char filler)
{
    if (filler != 0)
    {
        std::cout << "  " << std::string(length, filler) << std::endl;
    }
}

template <class T>
void print_row(const std::string &name, T value, char headliner = 0, char bottomliner = 0)
{
    print_ruller(80, headliner);
    std::cout << " | "
              << std::left << std::setw(20) << name
              << " | " << std::left << std::setw(8) << value << std::right << std::setw(50) << " | " << std::endl;
    print_ruller(80, bottomliner);
}

void dummy() {}

void stats_test()
{
    test::TestExecutionEngine executor;
    if (executor.executed_tests() != 0)
    {
        throw std::runtime_error("Executed tests is not zero");
    }
    if (executor.passed_tests() != 0)
    {
        throw std::runtime_error("Passed tests is not 0");
    }
    executor.run_test(dummy);
    if (executor.executed_tests() != 1)
    {
        throw std::runtime_error("Executed tests is not 1");
    }
    if (executor.passed_tests() != 1)
    {
        throw std::runtime_error("Passed tests is not 1");
    }
}

int main()
{
    test::TestExecutionEngine executor;
    try
    {
        executor.run_test(stats_test);
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    print_row("Executed tests", executor.executed_tests(), '=', '=');
    return 0;
}
