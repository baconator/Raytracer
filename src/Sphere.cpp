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
    /*auto xs = compare.start[0];
    auto ys = compare.start[1];
    auto zs = compare.start[2];

    auto xd = compare.through[0];
    auto yd = compare.through[1];
    auto zd = compare.through[2];

    auto x0 = this->centre[0];
    auto y0 = this->centre[1];
    auto z0 = this->centre[2];

    auto A = pow(xd, 2) + pow(yd, 2) + pow(zd, 2);
    auto B = 2*(xd*(xs-x0) + yd*(ys-y0) + zd*(zs-z0));
    auto C = pow(xs-x0, 2) + pow(ys-y0, 2) + pow(zs-z0, 2) - pow(r, 2);

    auto discriminant = pow(B, 2) - (4*A*C);
    if(discriminant < 0.0f) return 0.0f;
    auto t1 = (-1*B+sqrt(discriminant))/(2*A);
    auto t2 = (-1*B-sqrt(discriminant))/(2*A);
    return fmin(t1, t2);*/

    // Wikipedia
    auto c = this->centre;
    auto r = this->radius;
    auto l = compare.through;
    auto o = compare.start;
    auto A = l.squaredNorm();
    auto B = 2*(l.dot(o-c));
    auto C = (o-c).squaredNorm()-pow(r, 2);
    auto discriminant = pow(B, 2)-4*A*C;
    if(discriminant < 0.0f) return 0.0f;
    auto d1 = (-1*B+sqrt(discriminant))/(2*A);
    auto d2 = (-1*B-sqrt(discriminant))/(2*A);
    return fmin(d1, d2);
}

std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Sphere::Colour(Ray& compare){
    return std::make_tuple(128, 0, 128, 255);
}