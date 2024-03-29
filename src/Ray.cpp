//
// Created by bacon on 3/20/15.
//

#include "Ray.h"

Ray::Ray(Eigen::Vector4f start, Eigen::Vector4f through)
        : start(start),
          through(through){
}

Eigen::Vector4f Ray::Point(float d){
    return this->start + d*(this->through);
}