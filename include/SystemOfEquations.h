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
    matrix<T> _jacobi(matrix<T> A, vector<T> b, T tol=0.00001, int max_iters=1000){

    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    matrix<T> _gauss_seidel(matrix<T> A, vector<T> b, T tol=0.00001, int max_iters=1000){

    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    matrix<T> _stationary_richardson(matrix<T> A, vector<T> b, T tol=0.00001, int max_iters=1000){

    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    matrix<T> _basic_stationary(matrix<T> A, vector<T> b, T tol=0.00001, int max_iters=1000){
        const auto I = identity_matrix(A.size1(), A.size2());
        auto iter_matrix = I - A;
        
    }

}

#endif //COMA_SYSTEMOFEQUATIONS_H
