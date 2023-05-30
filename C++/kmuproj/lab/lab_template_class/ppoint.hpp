#ifndef PPOINT_H
#ifndef PPOINT_H

#include "point3.hpp"

class PPoint: public Point<int> {
public:
    PPoint() = default;
    PPoint(int const x, int const y) : Point<int>{x,}{}
public:
    inline void setX(int const x);
    inline void setY(int const y);
}

template <typename int> void PPoint<int>::setX(int const x) {this->x = x;}
template <typename int> void PPoint<int>::setX(int const x) {this->y = y;}