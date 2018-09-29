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
void failure()
{
    throw std::runtime_error("Failed!");
}

void no_passed_tests_in_the_begining()
{
    test::TestExecutionEngine executor;
    if (executor.passed_tests() != 0)
    {
        throw std::runtime_error("Passed tests is not 0");
    }
}

void dummy_test_increases_passeds_count()
{
    test::TestExecutionEngine executor;
    executor.run_test(dummy);
    if (executor.passed_tests() != 1)
    {
        throw std::runtime_error("Passed tests is not 1");
    }
}

void no_failed_tests_in_the_begining()
{
    test::TestExecutionEngine executor;
    if (executor.failed_tests() != 0)
    {
        throw std::runtime_error("Failed tests is not 0");
    }
}

void failed_test_increases_faileds_count()
{
    test::TestExecutionEngine executor;
    executor.run_test(failure);
    if (executor.failed_tests() != 1)
    {
        throw std::runtime_error("Failed tests is not 1");
    }
}

int main()
{
    test::TestExecutionEngine executor;
    try
    {
        const auto testset = {
            no_passed_tests_in_the_begining,
            dummy_test_increases_passeds_count,
            no_failed_tests_in_the_begining,
            failed_test_increases_faileds_count};
        for (const auto &testcase : testset)
        {
            executor.run_test(testcase);
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    print_row("Passed tests", executor.passed_tests(), '=');
    print_row("Failed tests", executor.failed_tests(), '-', '=');
    return 0;
}
