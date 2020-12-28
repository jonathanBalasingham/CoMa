//
// Created by jon on 12/18/20.
//

#ifndef COMA_SYSTEMOFEQUATIONS_H
#define COMA_SYSTEMOFEQUATIONS_H

#include <boost/numeric/ublas/matrix.hpp>

namespace CoMa {
    using namespace boost::numeric::ublas;

    template<
            typename T,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    matrix<T> jacobi(matrix<T>, vector<T> b, T tol=0.00001, int max_iters=1000){

    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    matrix<T> gauss_seidel(matrix<T>, vector<T> b, T tol=0.00001, int max_iters=1000){

    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    matrix<T> stationary_richardson(matrix<T>, vector<T> b, T tol=0.00001, int max_iters=1000){

    }


}

#endif //COMA_SYSTEMOFEQUATIONS_H
