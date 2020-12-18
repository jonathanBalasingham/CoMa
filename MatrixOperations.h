//
// Created by jon on 12/18/20.
//

#ifndef COMA_MATRIXOPERATIONS_H
#define COMA_MATRIXOPERATIONS_H

#include <iterator>

namespace CoMa {

    struct Matrix {
        float* data;
        int i,j = 0;
    };

    Matrix* empty(int i, int j){
        Matrix* m = new Matrix();
        m->i = i;
        m->j = j;

        m->data = new float[i*j];

        return m;
    }

    Matrix* zeros(int i, int j){
        auto m = empty(i,j);
        for(int i = 0; i < m->i * m->j; i++)
            m->data[i] = 0;
        return m;
    }

    Matrix* ones(int i, int j){
        auto m = empty(i,j);
        for(int i = 0; i < m->i * m->j; i++)
            m->data[i] = 1;
        return m;
    }

    Matrix* copy(Matrix A){
        auto m = new Matrix();
        m->i = A.i;
        m->j = A.j;
        for(int i = 0; i < A.i * A.j; i++)
            m->data[i] = A.data[i];

        return m;
    }

    Matrix operator*(Matrix A, Matrix B){

    }

    Matrix operator*(float a, Matrix A){
        auto m = new Matrix();
        for(int i = 0; i < A.i * A.j; i++)
            m->data[i] = a *  A.data[i];
        return m;
    }

    Matrix operator+(Matrix A, Matrix B){

    }

    Matrix operator-(Matrix A, Matrix B){
        return A + (-1.0 * B);
    }

    Matrix lower_triangle(float ** A){

    }

    Matrix upper_triangle(Matrix A){

    }

    Matrix strict_lower_triangle(Matrix A){

    }

    Matrix strict_upper_triangle(Matrix A){

    }

    Matrix transpose(Matrix A){

    }


}

#endif //COMA_MATRIXOPERATIONS_H
