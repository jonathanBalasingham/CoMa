//
// Created by jon on 2/18/21.
//

#ifndef COMA_ODESOLUTION_HPP
#define COMA_ODESOLUTION_HPP

#include <type_traits>

#include <boost/numeric/ublas/vector.hpp>

template<typename T,
        typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class ODESolution {
    boost::numeric::ublas::vector<T> get_t(){ return t;}
    boost::numeric::ublas::vector<T> get_u(){ return u;}
private:
    boost::numeric::ublas::vector<T> t;
    boost::numeric::ublas::vector<T> u;
};


#endif //COMA_ODESOLUTION_HPP
