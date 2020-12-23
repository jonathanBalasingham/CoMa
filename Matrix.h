//
// Created by jon on 12/19/20.
//

#ifndef COMA_MATRIX_H
#define COMA_MATRIX_H

#include <iterator>
#include <tuple>

class Matrix {
public:
    explicit Matrix(std::tuple<int,int> sh){ i=std::get<0>(sh); j=std::get<1>(sh); data=new float[i*j]; set_all(0.);}
    Matrix(int a, int b){ i = a; j = b; data = new float[i*j]; set_all(0.); }
    // this is bad
    Matrix(int a, int b, float* d){ i = a; j = b; data = d; }
    ~Matrix(){ delete [] this->data; }
    [[nodiscard]] std::tuple<int,int> shape() const { return std::make_tuple(i,j); }
    [[nodiscard]] int inline entries() const{ return this->i * this->j; }
    [[nodiscard]] int inline get_i() const { return i; }
    [[nodiscard]] int inline get_j() const { return j; }
    [[nodiscard]] float get(int x, int y) const { return data[x*i + y]; }
    [[nodiscard]] float get(int x) const { return data[x]; }
    void set(int x, float el) const { data[x] = el; }
    void set(int x, int y, float z){ data[x*i + y] = z; }
    static Matrix* zeros(int i, int j){ return init_all(i,j, 0.); }
    static Matrix* ones(int i, int j){ return init_all(i,j, 1.); }
    static Matrix* zeros(std::tuple<int,int> sh){ return zeros(std::get<0>(sh), std::get<1>(sh)); }
    static Matrix* ones(std::tuple<int,int> sh){ return zeros(std::get<0>(sh), std::get<1>(sh)); }

    float operator[](int i) const {
        return this->data[i];
    }

    Matrix* copy(){
        auto m = new Matrix(this->shape());
        for(int ind = 0; ind < entries(); ind++)
            m->data[ind] = data[ind];
        return m;
    }

    Matrix* reshape(int x, int y){
        if (x*y != i*j)
            throw std::invalid_argument("Cannot reshape from " + std::to_string(i) + "," + std::to_string(j) + "to" + std::to_string(x) + "," + std::to_string(y));
        auto m = copy();
        m->i = x; m->j = y;
        return m;
    }

    std::string toString(){
        std::string m_as_str = "";
        for (int a = 0; a < entries(); a++){
            m_as_str += " " + std::to_string(data[a]) + " ";
            if ((a+1) % get_j() == 0) m_as_str += "\n";
        }
        return m_as_str;
    }

private:
    float* data;
    int i,j = 0;
    static Matrix* init_all(int a, int b, float e){
        auto m = new Matrix(a,b);
        for(a = 0; a < m->entries(); a++) m->data[a] = e;
        return m;
    }

    void set_all(float el){
        for(int a = 0; a < entries(); a++) data[a] = el;
    }
};

#endif //COMA_MATRIX_H
