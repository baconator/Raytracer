//
// Created by bacon on 3/21/15.
//

#ifndef _ASSIGNMENT3_LIGHT_H_
#define _ASSIGNMENT3_LIGHT_H_

#include "Eigen/Dense"

class Light {
public:
    Eigen::Vector4f position;
    Eigen::Vector4f colour;
    uint8_t intensity;
    Light(Eigen::Vector4f position, Eigen::Vector4f colour, uint8_t intensity);
};


#endif //_ASSIGNMENT3_LIGHT_H_
