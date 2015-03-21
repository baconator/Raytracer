//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_INTERSECTABLE_H_
#define _ASSIGNMENT3_INTERSECTABLE_H_


#include "Ray.h"

class Intersectable {
public:
    virtual float Intersect(Ray compare);
    virtual std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Colour(Ray compare);
};


#endif //_ASSIGNMENT3_INTERSECTABLE_H_
