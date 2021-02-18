//
// Created by jon on 2/17/21.
//

#ifndef COMA_ODEPROBLEM_HPP
#define COMA_ODEPROBLEM_HPP

#include <array>
#include <boost/numeric/ublas/vector.hpp>
#include "../util.h"

// TODO: Possible type switch to std::vector
template<typename T,
        typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class ODEProblem {
public:
    ODEProblem(T f(T), std::tuple<T> tspan, std::vector<T> u0): tspan(tspan), u0(u0) { f = f; };
    boost::numeric::ublas::vector<T> solve();
private:
    T f(T);
    std::tuple<T> tspan;
    boost::numeric::ublas::vector<T> u0;
};

template<typename T, typename X>
boost::numeric::ublas::vector<T> ODEProblem<T, <unnamed>>::solve() {
    return boost::numeric::ublas::vector<T>();
}


#endif //COMA_ODEPROBLEM_HPP
