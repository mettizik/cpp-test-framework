#include <cpptest/TestExecutionEngine.h>

void test::TestExecutionEngine::run_test(test::test_case testcase)
{
    ++_executed_tests;
    testcase();
}

uint64_t test::TestExecutionEngine::executed_tests() const
{
    return _executed_tests;
}

uint64_t test::TestExecutionEngine::passed_tests() const
{
    return 1;
}
