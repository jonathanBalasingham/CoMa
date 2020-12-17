//
// Created by jon on 12/8/20.
//

#ifndef COMA_UTIL_H
#define COMA_UTIL_H

namespace CoMa {
    typedef void (* RealValuedFunc)(float x);

    struct Interval {
        float a;
        float b;
        Interval(float a, float b) : a(a), b(b) {}
    };

}

#endif //COMA_UTIL_H
