//
// Created by jon on 12/19/20.
//

#ifndef COMA_MATRIX_H
#define COMA_MATRIX_H

#include <iterator>
#include <tuple>

class Matrix {
public:
    float operator[](int i) const {
        return this->data[i];
    }
    Matrix(){}
    Matrix(int i, int j){
        this->i = i;
        this->j = j;
        this->data = new float[i*j];
    }
    ~Matrix(){ delete [] this->data; }
    [[nodiscard]] std::tuple<int,int> shape() const { return std::make_tuple(this->i, this->j); }
    int inline entries() const{ return this->i * this->j; }

    static Matrix* zeros(int i, int j){ return init_all(i,j, 0.); }
    static Matrix* ones(int i, int j){ return init_all(i,j, 1.); }

    Matrix* copy(){
        auto m = new Matrix();
        for(int ind = 0; i < entries(); ind++)
            m->data[ind] = data[ind];
        return m;
    }

    Matrix operator*(Matrix const &B){
        if (j != B.i)
            throw std::invalid_argument("Number of columns in A must match number of rows in B");

        auto C = new Matrix(i, B.j);
        for (int h = 0; h < i; h++)
            for (int k = 0; k < j; k++)
                for (int l = 0; l < B.j; l++)
                    C->data[i*C->i + j] += data[h*i + k] * B.data[l*B.j+k];
    }

    Matrix* operator*(float alpha) const {
        auto m = new Matrix(this->i,this->j);
        for(int a = 0; a < entries(); a++) { m->data[a] = alpha*data[a]; }
        return m;
    }

    Matrix* operator+(const Matrix &B) const {

        if(B.shape() != this->shape()) throw std::invalid_argument("Matrices must have the same shape.");
        auto m = new Matrix(i,j);
        for (int a = 0; a < entries(); a++) { m->data[a] = data[a] + B[a]; }
        return m;
    }

    Matrix* operator-(const Matrix &B){
        if(B.shape() != this->shape()) throw std::invalid_argument("Matrices must have the same shape.");
        auto m = new Matrix(i,j);
        for (int a = 0; a < entries(); a++) { m->data[a] = data[a] - B[a]; }
        return m;
    }
private:
    float* data;
    int i,j = 0;
    static Matrix* init_all(int i, int j, float e){
        auto m = new Matrix(i,j);
        for(int i = 0; i < m->entries(); i++) m->data[i] = e;
        return m;
    }
};

#endif //COMA_MATRIX_H
