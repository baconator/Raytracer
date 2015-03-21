//
// Created by bacon on 3/21/15.
//

#include "Light.h"
Light::Light(Eigen::Vector4f position, Eigen::Vector4f colour, uint8_t intensity)
        : position(position),
          colour(colour),
          intensity(intensity){
}