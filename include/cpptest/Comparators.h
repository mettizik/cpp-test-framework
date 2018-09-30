#include <sstream>

namespace test
{
template <class T1, class T2>
void expect_eq(T1 expected, T2 actual)
{
    if (expected != actual)
    {
        std::stringstream error_info;
        error_info << actual << " is not equal to " << expected;
        throw std::runtime_error(error_info.str());
    }
}
}
