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

private:
};
}
