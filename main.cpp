//
// Created by jon on 12/7/20.
//
#include "library.h"
#include "NonlinearEquations.h"


float f(float x){
    return  2*x*x -5. + x;
}

int main(){
    auto ab = new CoMa::Interval(-10., 5);

    float answer1 = CoMa::bisection(f, ab, .0000001);
    std::cout << answer1 << std::endl;

    float answer2 = CoMa::newton(f, ab, .0000001);
    std::cout << answer2 << std::endl;

    float answer3 = CoMa::secant(f, ab, .0000001);
    std::cout << answer3 << std::endl;

    float answer4 = CoMa::chord(f, ab, .0000001);
    std::cout << answer4 << std::endl;

    delete ab;
    return 0;
}
