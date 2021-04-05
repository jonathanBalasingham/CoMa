//
// Created by jon on 12/7/20.
//
#include "library.h"
#include "include/NonlinearEquations.hpp"
#include "deprecated/MatrixOperations.h"


float f(float x){
    return  2*x*x -5. + x;
}

int main(){
    using namespace CoMa;
    auto ab = new CoMa::Interval(-10., 5);

    float answer1 = CoMa::bisection(&f, ab, .0000001);
    std::cout << answer1 << std::endl;

    float answer2 = CoMa::newton(f, ab, .0000001);
    std::cout << answer2 << std::endl;

    float answer3 = CoMa::secant(f, ab, .0000001);
    std::cout << answer3 << std::endl;

    float answer4 = CoMa::chord(f, ab, .0000001);
    std::cout << answer4 << std::endl;

    auto m = Matrix::zeros(3,3);
    std::cout << m->toString() << std::endl;

    auto m2 = Matrix::ones(3,3);
    std::cout << m2->toString() << std::endl;

    auto m3 = CoMa::diagonal(*m2);
    std::cout << "diagonal: " << std::endl;
    std::cout << m3->toString() << std::endl;

    auto m5 = CoMa::strict_upper_triangle(*m2);
    std::cout << "strict upper triangle: " << std::endl;
    std::cout << m5->toString() << std::endl;

    auto m4 = CoMa::strict_lower_triangle(*m2);
    std::cout << "strict lower triangle: " << std::endl;
    std::cout << m4->toString() << std::endl;

    auto m6 = CoMa::upper_triangle(*m2);
    std::cout << "upper triangle: " << std::endl;
    std::cout << m6->toString() << std::endl;

    auto m7 = CoMa::lower_triangle(*m2);
    std::cout << "lower triangle: " << std::endl;
    std::cout << m7->toString() << std::endl;

    auto m8 = m2->reshape(1,9);
    std::cout << "reshaping to [1,9]" << std::endl;
    std::cout << m8->toString() << std::endl;

    auto m9 = *m6 + *m7;
    std::cout << "m7 + m6 = " << std::endl;
    std::cout << m9->toString() << std::endl;

    auto m10 = *m6 - *m7;
    std::cout << "m7 - m6 = " << std::endl;
    std::cout << m10->toString() << std::endl;

    auto m11 = 5.0 * *m6;
    std::cout << "5.0 *  m6 = " << std::endl;
    std::cout << m11->toString() << std::endl;

    auto m12 = *m6 * *m6;
    std::cout << "m6 *  m6 = " << std::endl;
    std::cout << m12->toString() << std::endl;


    delete ab;
    delete m7;
    delete m5;


    return 0;
}
