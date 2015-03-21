//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_CAMERA_H_
#define _ASSIGNMENT3_CAMERA_H_

#include <tuple>
#include "Ray.h"
#include <vector>

// A camera that we assume has a center on the origin and its pixels are squares.
// We only need its width/height in world coordinates and a ratio, ten..
// ... also the distance to the ray point source.
class Camera {
public:
    float width;
    float height;
    float screenToWorldRatio;
    float offset;
    Camera(float width, float height, float ratio, float offset); // Offset refers to how far away the camera is from a screen centered at the origin.
    std::vector<Ray> Cast();
};


#endif //_ASSIGNMENT3_CAMERA_H_
