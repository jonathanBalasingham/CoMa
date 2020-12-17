//
// Created by jon on 12/7/20.
//
#include "library.h"
#include "NonlinearEquations.h"


float f(float x){
    return x-4.;
};

int main(){
    auto ab = new CoMa::Interval(-1., 5);

    float answer1 = CoMa::bisection(f, ab, .0000001);
    std::cout << answer1 << std::endl;

    float answer2 = CoMa::newton(f, ab, .0000001);
    std::cout << answer2 << std::endl;
    delete ab;
    return 0;
}
