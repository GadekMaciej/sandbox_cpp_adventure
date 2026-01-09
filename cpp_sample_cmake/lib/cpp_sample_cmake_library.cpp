#include <iostream>
#include <cmath>
#include <format>

namespace {
    // a hack square root calculation using simple operations
    double mysqrt(double x)
    {
        if (x <= 0) {
            return 0;
        }

        double result = x;

        // do ten iterations
        for (int i = 0; i < 10; ++i) {
            if (result <= 0) {
                result = 0.1;
            }
            double delta = x - (result * result);
            result = result + 0.5 * delta / result;

            std::cout << std::format("Computing [cpp 21] sqrt of {} to be {}\n", x, result);
        }
        return result;
    }
}

namespace cpp_library {
    double sqrt(double x)
    {
#ifdef TUTORIAL_USE_STD_SQRT
        std::cout << std::format("Using std::sqrt");
        return std::sqrt(x);
#else
        return mysqrt(x);
#endif
    }
}