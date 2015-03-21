//
// Created by bacon on 3/20/15.
//

#include "Camera.h"
#include <cmath>
#include "Eigen/Dense"
Camera::Camera(float width, float height, float ratio, float offset)
        :width(width),
         height(height),
         screenToWorldRatio(ratio),
         offset(offset) {
}

std::vector<Ray> Camera::Cast(){
    // Get the world-coordinate for the top-leftmost point.
    float startX = -1*(this->width/2)*this->screenToWorldRatio;
    float startY = (this->height/2)*this->screenToWorldRatio;
    Eigen::Vector4f start(startX, startY, this->offset, 1.0f);

    std::vector<Ray> rays;
    for(auto pixelY = 0; pixelY < this->height; pixelY += 1){
        for(auto pixelX = 0; pixelX < this->width; pixelX += 1){
            // Subtract from y (positive is up), add to x (positive is right) (i.e. top left to bottom-right)
            Eigen::Vector4f through(startX+(pixelX*this->screenToWorldRatio), startY-(pixelY*this->screenToWorldRatio), 0.0f, 1.0f);
            rays.push_back(Ray(start, through));
        }
    }
    return rays;
}