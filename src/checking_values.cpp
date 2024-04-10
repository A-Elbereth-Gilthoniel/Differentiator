#include "differentiator.h"

int cmp_with_number(double number1, double number2)
{
    const double eps = 1e-5;
    return number2 - eps <= number1 && number1 <= number2 + eps;
}
