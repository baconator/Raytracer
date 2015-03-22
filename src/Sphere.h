//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_SPHERE_H_
#define _ASSIGNMENT3_SPHERE_H_


#include "Intersectable.h"
#include "MaterialParameters.h"
#include "Eigen/Dense"

class Sphere: public Intersectable {
private:
    Eigen::Vector4f centre;
    float radius;
    MaterialParameters material;
public:
    Sphere(Eigen::Vector4f centre, float radius, MaterialParameters material);
    float Intersect(Ray& compare);
    Eigen::Vector4f Colour(Ray& compare, std::vector<Light>& lights, const Eigen::Vector4f& ambient);
};


#endif //_ASSIGNMENT3_SPHERE_H_
