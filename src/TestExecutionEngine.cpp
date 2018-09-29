#include <iostream>
#include <cpptest/TestExecutionEngine.h>

void test::TestExecutionEngine::run_test(test::test_case testcase)
{
    try
    {
        testcase();
        ++_passed_tests_count;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Test failed! Error: " << ex.what() << std::endl;
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
