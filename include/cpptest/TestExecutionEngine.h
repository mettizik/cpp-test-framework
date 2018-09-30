#pragma once
#include <sstream>
#include <stdint.h>
#include <vector>
#include <functional>

namespace test
{
typedef bool execution_info;
typedef std::function<void()> test_case;
typedef std::vector<test_case> test_suite;

class TestExecutionEngine
{
public:
  void run_testset(const test_suite &testset);
  void run_test(test_case testcase);
  uint64_t passed_tests() const;
  uint64_t failed_tests() const;

  std::string errors() const;

private:
  uint64_t _passed_tests_count = 0;
  uint64_t _failed_tests_count = 0;
  std::stringstream _errors_log;
};
}
