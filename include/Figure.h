#pragma once
#include "Point.h"
#include <iostream>
#include <memory>

template <typename T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual Point<T> center() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual operator double() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& f) {
        f.print(os);
        return os;
    }
};
