#include <sstream>

namespace test
{
#define expect_eq(expected, actual)                                                              \
    {                                                                                            \
        if ((expected) != (actual))                                                              \
        {                                                                                        \
            std::stringstream error_info;                                                        \
            error_info << __FUNCTION__ << ": " << (actual) << " is not equal to " << (expected); \
            throw std::runtime_error(error_info.str());                                          \
        }                                                                                        \
    }
}
