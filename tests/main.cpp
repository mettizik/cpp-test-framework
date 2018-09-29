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

int main()
{
    test::TestExecutionEngine executor;
    print_row("Total tests", executor.total_tests(), '=', '=');
    return 0;
}
