//
// Created by jon on 12/7/20.
//
#include "library.h"
#include "NonlinearEquations.h"


float f(float x){
    return x-4.;
};

int main(){
    hello();

    auto ab = new CoMa::Interval(-1., 5);

    float answer = CoMa::bisection(f, ab, .0000001);
    std::cout << answer << std::endl;
    delete ab;
    return 0;
}
