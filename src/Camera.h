//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_CAMERA_H_
#define _ASSIGNMENT3_CAMERA_H_

#include <tuple>
#include "Ray.h"
#include <vector>

class Camera {
public:
    int width;
    int height;
    int offset;
    Camera(int width, int height, int offset); // Offset refers to how far away the camera is from a screen centered at the origin.
    std::vector<Ray> Cast();
};


#endif //_ASSIGNMENT3_CAMERA_H_
