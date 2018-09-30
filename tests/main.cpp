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
              << " | " << std::left << std::setw(55) << value << std::right << " | " << std::endl;
    print_ruller(80, bottomliner);
}

test::test_suite engine_tests();
test::test_suite comparators_tests();

void run_tests(const test::test_suite &suite, const std::string &name)
{
    test::TestExecutionEngine executor;
    executor.run_testset(suite);
    print_row("Test suite", name, '=');
    print_row("Passed tests", executor.passed_tests(), '=');
    print_row("Failed tests", executor.failed_tests(), '-', '=');
}

int main()
{
    run_tests(engine_tests(), "Execution engine tests");
    run_tests(comparators_tests(), "Comparators tests");
    return 0;
}
