//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_INTERSECTABLE_H_
#define _ASSIGNMENT3_INTERSECTABLE_H_


#include "Ray.h"
#include "Light.h"
#include "Eigen/Dense"
#include <vector>

class Intersectable {
public:
    virtual float Intersect(Ray& compare) = 0;
    virtual Eigen::Vector4f Colour(Ray& compare, std::vector<Light>& lights, const Eigen::Vector4f& ambient) = 0;
};


#endif //_ASSIGNMENT3_INTERSECTABLE_H_
