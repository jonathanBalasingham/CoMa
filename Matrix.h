//
// Created by jon on 12/19/20.
//

#ifndef COMA_MATRIX_H
#define COMA_MATRIX_H

#include <iterator>
#include <tuple>

class Matrix {
public:
    Matrix(std::tuple<int,int> sh){ i=std::get<0>(sh); j=std::get<1>(sh); data=new float[i*j]; }
    Matrix(int a, int b){ i = a; j = b; data = new float[i*j]; }
    ~Matrix(){ delete [] this->data; }
    [[nodiscard]] std::tuple<int,int> shape() const { return std::make_tuple(this->i, this->j); }
    [[nodiscard]] int inline entries() const{ return this->i * this->j; }
    int get_i() const { return i; }
    int get_j() const { return j; }
    float get(int x, int y) const { return data[x*i + y]; }
    float set(int x, int y, float z){ return data[x*i + y] = z; }
    static Matrix* zeros(int i, int j){ return init_all(i,j, 0.); }
    static Matrix* ones(int i, int j){ return init_all(i,j, 1.); }
    static Matrix* zeros(std::tuple<int,int> sh){ return zeros(std::get<0>(sh), std::get<1>(sh)); }
    static Matrix* ones(std::tuple<int,int> sh){ return zeros(std::get<0>(sh), std::get<1>(sh)); }

    float operator[](int i) const {
        return this->data[i];
    }

    Matrix* copy(){
        auto m = new Matrix(this->shape());
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
        if(B.shape() != shape()) throw std::invalid_argument("Matrices must have the same shape.");
        auto m = new Matrix(i,j);
        for (int a = 0; a < entries(); a++) { m->data[a] = data[a] - B[a]; }
        return m;
    }

    Matrix* reshape(int x, int y){
        auto m = copy();
        m->i = x;
        m->j = y;
        return m;
    }

private:
    float* data;
    int i,j = 0;
    static Matrix* init_all(int a, int b, float e){
        auto m = new Matrix(a,b);
        for(a = 0; a < m->entries(); a++) m->data[a] = e;
        return m;
    }
};

#endif //COMA_MATRIX_H
