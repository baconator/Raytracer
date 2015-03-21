//
// Created by bacon on 3/20/15.
//

#include "Sphere.h"
#include <cmath>
Sphere::Sphere(Eigen::Vector4f centre, float radius)
        : centre(centre),
          radius(radius){

}

float Sphere::Intersect(Ray& compare) {
    // Wikipedia
    auto l = compare.through;
    auto direction = compare.start-this->centre;
    auto A = l.squaredNorm();
    auto B = 2*(l.dot(direction));
    auto C = (direction).squaredNorm()-pow(this->radius, 2);
    auto discriminant = pow(B, 2)-4*A*C;
    if(discriminant < 0.0f) return 0.0f;
    auto d1 = (-1*B+sqrt(discriminant))/(2*A);
    auto d2 = (-1*B-sqrt(discriminant))/(2*A);
    return fmin(d1, d2);
}

Eigen::Vector4f Sphere::Colour(Ray& compare, std::vector<Light>& lights){
    return Eigen::Vector4f(128, 0, 128, 255);
}