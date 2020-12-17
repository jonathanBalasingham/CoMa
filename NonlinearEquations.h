#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "util.h"

namespace CoMa {

    /*
     *
     *
     *
     */
    float bisection(float f(float), Interval *ab, float tol = .00001, int max_iter = 1000, bool verbose = true) {
        int k = 0;
        float xk;
        Interval ab_copy = Interval(ab->a, ab->b);

        if (std::abs(f(ab->a)) <= tol)
            return ab->a;
        else if (std::abs(f(ab->b)) <= tol)
            return ab->b;


        while (k <= max_iter) {
            xk = (ab_copy.a + ab_copy.b) / 2;
            if (std::abs(f(xk)) <= tol) {
                if (verbose)
                    std::cout << "Reached solution in " << k << " iterations" << std::endl;
                return xk;
            }

            if (f(xk) * f(ab_copy.a) > 0) {
                ab_copy.a = xk;
                k++;
            } else if (f(xk) * f(ab_copy.a) < 0) {
                ab_copy.b = xk;
                k++;
            }

            std::cout << f(xk) << " , ";
        }

        if (verbose)
            std::cout << "Warning: max iterations reached without reaching tolerance" << std::endl;

        return xk;
    }

    float newton(RealValuedFunc f, Interval *ab, float tol = .00001, int max_iter = 1000) {
        return 0.;
    }

    float secant(float f(float), Interval *ab, float tol = .00001, int max_iter = 1000, bool verbose = true) {

        return 0.;
    }
}