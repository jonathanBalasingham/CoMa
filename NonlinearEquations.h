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
    float bisection(float f(float), Interval *ab, float tol = .00001, int max_iter = 10000, bool verbose = true) {
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

        }

        if (verbose)
            std::cout << "Warning: max iterations reached without reaching tolerance" << std::endl;

        return xk;
    }

    /*
     *
     *
     * */
    float newton(float f(float), Interval *ab, float tol = .00001, int max_iter = 10000, bool verbose = true) {
        float xk = (ab->a + ab->b) / 2;
        int k = 0;
        while (k < max_iter) {

            xk = xk - f(xk) / derivative_at(f, xk);

            if (std::abs(f(xk)) <= tol) {
                if (verbose) {
                    std::cout << "Converged in " << k << " iterations " << std::endl;
                }
                return xk;
            }

            k++;
        }

        if (verbose)
            std::cout << "Warning: max iterations reached without reaching tolerance" << std::endl;

        return xk;
    }

    /*
     *  TODO: initialization here could be more optimized
     *
     * */
    float secant(float f(float), Interval *ab, float tol = .00001, int max_iter = 10000, bool verbose = true) {

        float xk = (ab->a + ab->b) / 2;
        float xk_1 = xk / 2;

        int k = 0;
        float temp;

        while (k < max_iter) {
            temp = xk;

            xk = xk - f(xk) * ((xk - xk_1) / (f(xk) - f(xk_1)));
            xk_1 = temp;

            if (std::abs(f(xk)) <= tol) {
                if (verbose) {
                    std::cout << "Converged in " << k << " iterations " << std::endl;
                }
                return xk;
            }
            k++;
        }

        if (verbose)
            std::cout << "Warning: max iterations reached without reaching tolerance" << std::endl;

        return xk;
    }

    /*
     *
     *
     * */
    float chord(float f(float), Interval *ab, float tol = .00001, int max_iter = 10000, bool verbose = true) {
        float xk = (ab->a + ab->b) / 2;
        int k = 0;
        float q = (f(ab->b) - f(ab->a)) / (ab->b - ab->a);

        while (k < max_iter) {

            xk = xk - f(xk) / q;

            if (std::abs(f(xk)) <= tol) {
                if (verbose) {
                    std::cout << "Converged in " << k << " iterations " << std::endl;
                }
                return xk;
            }

            k++;
        }

        if (verbose)
            std::cout << "Warning: max iterations reached without reaching tolerance" << std::endl;

        return xk;
    }
}