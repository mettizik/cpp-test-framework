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

int main()
{
    test::TestExecutionEngine executor;
    try
    {
        executor.run_test(dummy);
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    print_row("Passed tests", executor.passed_tests(), '=');
    return 0;
}
