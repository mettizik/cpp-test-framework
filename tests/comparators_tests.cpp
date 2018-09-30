#include <string>
#include <cpptest/cpptest.h>
#include <exception>

void expect_eq_does_not_throw_for_equal_values()
{
    expect_eq(0, 0);
}

void expect_eq__throws_for_not_equal_values()
{
    try
    {
        expect_eq(1, 0);
    }
    catch (const std::exception &)
    {
        return;
    }
    throw std::runtime_error("expect eq did not throw");
}

void expect_eq_throws_error_with_expected_and_actual_values_described()
{
    try
    {
        expect_eq(1, 0);
    }
    catch (const std::exception &ex)
    {
        expect_eq(std::string(ex.what()), "expect_eq_throws_error_with_expected_and_actual_values_described: 0 is not equal to 1");
    }
}

test::test_suite comparators_tests()
{
    return {expect_eq_does_not_throw_for_equal_values,
            expect_eq__throws_for_not_equal_values,
            expect_eq_throws_error_with_expected_and_actual_values_described};
}
