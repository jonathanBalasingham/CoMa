//
// Created by jon on 12/18/20.
//

#ifndef COMA_MATRIXOPERATIONS_H
#define COMA_MATRIXOPERATIONS_H

#include "Matrix.h"
#include <math.h>

namespace CoMa {

    bool is_square(const Matrix &A){
        return std::get<0>(A.shape()) == std::get<1>(A.shape());
    }

    Matrix* lower_triangle(const Matrix &A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
        auto m = Matrix::zeros(A.shape());
        int i = std::get<0>(A.shape());
        int j = std::get<1>(A.shape());
        for (int a = 0; a < A.entries(); a++){
            if (a % i <= floor(j / 2) + 1 )
        }
        return m;
    }

    Matrix upper_triangle(Matrix A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
    }

    Matrix strict_lower_triangle(Matrix A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
    }

    Matrix strict_upper_triangle(Matrix A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
    }

    Matrix* transpose(const Matrix &A){
        auto m = new Matrix(A.get_j(), A.get_i());
        for (int a = 0; a < A.get_j(); a++){
            for (int b = 0; b < A.get_i(); b++){
                m->set(a, b, A.get(b,a));
            }
        }
        return m;
    }


}

#endif //COMA_MATRIXOPERATIONS_H
