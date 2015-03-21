//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_SPHERE_H_
#define _ASSIGNMENT3_SPHERE_H_


#include "Intersectable.h"
#include "Eigen/Dense"

class Sphere: public Intersectable {
private:
    Eigen::Vector4f centre;
    float radius;
public:
    Sphere(Eigen::Vector4f centre, float radius);
    float Intersect(Ray compare);
    std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Colour(Ray compare);
};


#endif //_ASSIGNMENT3_SPHERE_H_
