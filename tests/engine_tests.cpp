#include <string>
#include <sstream>
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
    expect_eq(0, executor.passed_tests());
}

void dummy_test_increases_passeds_count()
{
    test::TestExecutionEngine executor;
    executor.run_test(dummy);
    expect_eq(1, executor.passed_tests());
}

void no_failed_tests_in_the_begining()
{
    test::TestExecutionEngine executor;
    expect_eq(0, executor.failed_tests());
}

void failed_test_increases_faileds_count()
{
    test::TestExecutionEngine executor;
    executor.run_test(failure);
    expect_eq(1, executor.failed_tests());
}

void execution_engine_writes_failures_info_to_log()
{
    test::TestExecutionEngine executor;
    executor.run_test(failure);
    expect_eq(std::string("Failed!\n"), executor.errors());
}

test::test_suite engine_tests()
{
    return {
        no_passed_tests_in_the_begining,
        dummy_test_increases_passeds_count,
        no_failed_tests_in_the_begining,
        failed_test_increases_faileds_count,
        execution_engine_writes_failures_info_to_log};
}
