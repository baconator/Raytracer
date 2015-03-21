//
// Created by bacon on 3/20/15.
//

#include "Sphere.h"
#include <cmath>
Sphere::Sphere(Eigen::Vector4f centre, float radius)
        : centre(centre),
          radius(radius){

}

float Sphere::Intersect(Ray compare) {
    // Thanks to Wikipedia! http://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
    auto c = this->centre;
    auto r = this->radius;

    auto o = compare.start;
    auto l = compare.through.normalized();

    auto discriminant = pow(l.dot(o-c), 2) - (o-c).squaredNorm() + pow(r, 2);
    if(discriminant < 0.0f){
        return 0.0f;
    }else{
        auto squaredPart = sqrt(discriminant);
        auto freePart = -(l.dot(o-c));
        auto d1 = freePart + squaredPart;
        auto d2 = freePart - squaredPart;
        if(d1 < d2){
            return d1;
        }else{
            return d2;
        }
    }
}

std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Sphere::Colour(Ray compare){
    return std::make_tuple(128, 0, 128, 255);
}