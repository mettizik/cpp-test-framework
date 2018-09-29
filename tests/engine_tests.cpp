#include <string>
#include <cpptest/cpptest.h>
#include <exception>

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

test::test_suite engine_tests()
{
    return {
        no_passed_tests_in_the_begining,
        dummy_test_increases_passeds_count,
        no_failed_tests_in_the_begining,
        failed_test_increases_faileds_count};
}
