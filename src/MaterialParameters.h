//
// Created by bacon on 3/22/15.
//

#ifndef _ASSIGNMENT3_MODELPARAMETERS_H_
#define _ASSIGNMENT3_MODELPARAMETERS_H_

#include "Eigen/Dense"


struct MaterialParameters {
    Eigen::Vector4f specularReflectance;
    Eigen::Vector4f diffuseReflectance;
    Eigen::Vector4f ambientReflectance;
    float shininess;
};


#endif //_ASSIGNMENT3_MODELPARAMETERS_H_
