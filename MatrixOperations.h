//
// Created by jon on 12/18/20.
//

#ifndef COMA_MATRIXOPERATIONS_H
#define COMA_MATRIXOPERATIONS_H

#include "Matrix.h"
#include <cmath>

namespace CoMa {

    bool is_square(const Matrix &A){
        return std::get<0>(A.shape()) == std::get<1>(A.shape());
    }


    Matrix* diagonal(const Matrix &A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
        auto m = Matrix::zeros(A.shape());
        for (int a = 0; a < A.get_i(); a++){
            m->set(a,a, A.get(a,a));
        }
        return m;
    }

    Matrix* lower_triangle(const Matrix &A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
        auto m = Matrix::zeros(A.shape());

        for (int a = 0; a < A.get_i(); a++){
            for (int b = 0; b < A.get_j(); b++) {

                if (b <= a)
                    m->set(a,b, A.get(a,b));
            }
        }
        return m;
    }

    Matrix* upper_triangle(Matrix &A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
        auto m = Matrix::zeros(A.shape());
        for (int a = 0; a < A.get_i(); a++){
            for (int b = 0; b < A.get_j(); b++) {
                if (b >= a)
                    m->set(a,b, A.get(a,b));
            }
        }
        return m;
    }

    Matrix* strict_lower_triangle(Matrix &A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
        auto m = Matrix::zeros(A.shape());
        for (int a = 0; a < A.get_i(); a++){
            for (int b = 0; b < A.get_j(); b++) {
                if (b < a)
                    m->set(a,b, A.get(a,b));
            }
        }
        return m;
    }

    Matrix* strict_upper_triangle(Matrix &A){
        if (!is_square(A))
            throw std::invalid_argument("Matrix must be square");
        auto m = Matrix::zeros(A.shape());
        for (int a = 0; a < A.get_i(); a++){
            for (int b = 0; b < A.get_j(); b++) {
                if (b > a)
                    m->set(a,b, A.get(a,b));
            }
        }
        return m;
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

    Matrix* operator+(Matrix &A, Matrix &B) {
        if(B.shape() != A.shape()) throw std::invalid_argument("Matrices must have the same shape.");
        auto m = new Matrix(A.get_i(),A.get_j());
        for (int a = 0; a < A.get_i(); a++)
            for (int b = 0; b < A.get_j(); b++)
                m->set(a,b, A.get(a,b) + B.get(a,b));
        return m;
    }

    Matrix* operator-(const Matrix &A, const Matrix &B) {
        if(B.shape() != A.shape()) throw std::invalid_argument("Matrices must have the same shape.");
        auto m = new Matrix(A.get_i(),A.get_j());
        for (int a = 0; a < A.get_i(); a++)
            for (int b = 0; b < A.get_j(); b++)
                m->set(a,b, A.get(a,b) - B.get(a,b));
        return m;
    }

    Matrix* operator*(float alpha, Matrix &A) {
        auto m = new Matrix(A.get_i(),A.get_j());
        for(int a = 0; a < A.entries(); a++) { m->set(a, alpha*A.get(a)); }
        return m;
    }

    Matrix* operator*(const Matrix &A, const Matrix &B){
        if (A.get_j() != B.get_i())
            throw std::invalid_argument("Number of columns in A must match number of rows in B");
        auto C = new Matrix(A.get_j(), B.get_i());
        for (int h = 0; h < A.get_i(); h++)
            for (int k = 0; k < A.get_j(); k++)
                for (int l = 0; l < B.get_j(); l++)
                    C->set(h, l, C->get(h,l) + A.get(h, k) * B.get(k,l));
        return C;
    }

    float norm(const Matrix &M, int p=2){
        float acc = 0;
        for (int j = 0; j < M.entries(); j++)
            acc += pow(M[j],p);
        return pow(acc, 1/p);
    }

    float spectral_norm(const Matrix &M){

    }

}

#endif //COMA_MATRIXOPERATIONS_H
