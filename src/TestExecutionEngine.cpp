#include <iostream>
#include <cpptest/TestExecutionEngine.h>

void test::TestExecutionEngine::run_testset(const test_suite &testset)
{
    try
    {
        for (const auto &testcase : testset)
        {
            run_test(testcase);
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void test::TestExecutionEngine::run_test(test::test_case testcase)
{
    try
    {
        testcase();
        ++_passed_tests_count;
    }
    catch (const std::exception &ex)
    {
        ++_failed_tests_count;
    }
}

uint64_t test::TestExecutionEngine::passed_tests() const
{
    return _passed_tests_count;
}

uint64_t test::TestExecutionEngine::failed_tests() const
{
    return _failed_tests_count;
}
