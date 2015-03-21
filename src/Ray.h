//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_RAY_H_
#define _ASSIGNMENT3_RAY_H_

#include "Eigen/Dense"

class Ray{
public:
    Eigen::Vector4f start;
    Eigen::Vector4f through;
    Ray(Eigen::Vector4f start, Eigen::Vector4f through);
    Eigen::Vector4f Point(float d);
};


#endif //_ASSIGNMENT3_RAY_H_
