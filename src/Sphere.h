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
    float Intersect(Ray& compare);
    Eigen::Vector4f Colour(Ray& compare, std::vector<Light>& lights);
};


#endif //_ASSIGNMENT3_SPHERE_H_
