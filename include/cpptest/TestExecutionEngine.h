#include <stdint.h>
#include <vector>
#include <functional>

namespace test
{
typedef bool execution_info;
typedef std::function<void()> test_case;

class TestExecutionEngine
{
public:
  void run_test(test_case testcase);
  uint64_t passed_tests() const;
  uint64_t failed_tests() const;

private:
  uint64_t _passed_tests_count = 0;
  uint64_t _failed_tests_count = 0;
};
}
