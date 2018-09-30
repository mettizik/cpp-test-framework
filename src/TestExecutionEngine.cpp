#include <iostream>
#include <cpptest/TestExecutionEngine.h>

void test::TestExecutionEngine::run_testset(const test_suite &testset)
{
    for (const auto &testcase : testset)
    {
        run_test(testcase);
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
        _errors_log << ex.what() << std::endl;
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

std::string test::TestExecutionEngine::errors() const
{
    return _errors_log.str();
}
