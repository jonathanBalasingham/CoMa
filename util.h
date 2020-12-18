//
// Created by jon on 12/8/20.
//

#ifndef COMA_UTIL_H
#define COMA_UTIL_H

namespace CoMa {

    struct Interval {
        float a;
        float b;
        Interval(float begin, float end){
            if (end < begin){
                throw std::invalid_argument("Cannot create interval where a > b");
            } else {
                a = begin;
                b = end;
            }
        }
    };

    float derivative_at(float f(float), float x, float h=0.0001, std::string method="center") {
        if (method == "center") {
            return (f(x+h/2) - f(x-h/2)) / h;
        }

        if (method == "forward") {
            return (f(x+h) - f(x)) / h;
        }

        if (method == "backward"){
            return (f(x) - f(x-h)) / h;
        }

    }
}

#endif //COMA_UTIL_H
