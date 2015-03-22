//
// Created by bacon on 3/20/15.
//

#include "Sphere.h"
#include <cmath>
Sphere::Sphere(Eigen::Vector4f centre, float radius, MaterialParameters material)
        : centre(centre),
          radius(radius),
          material(material){
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

Eigen::Vector4f Sphere::Colour(Ray& compare, std::vector<Light>& lights, const Eigen::Vector4f& ambient){
    // https://en.wikipedia.org/wiki/Phong_reflection_model
    auto V = (compare.through-compare.start).normalized();
    auto d = this->Intersect(compare);
    auto x = compare.Point(d);
    auto N = (this->centre-x).normalized();

    Eigen::Vector4f I = this->material.ambientReflectance.cwiseProduct(ambient);
    for(auto& light : lights){
        auto L = (light.position-x).normalized();
        // http://en.wikipedia.org/wiki/Specular_reflection#Direction_of_reflection
        auto R = 2*(N.dot(L))*N-L;
        //I = static_cast<Eigen::Vector4f>(I + (this->material.diffuseReflectance*(L.dot(N))*light.colour + this->material.specularReflectance*pow(R.dot(V), this->material.shininess)*light.colour));
    }
    float inspect[] {I[0], I[1], I[2], I[3]};
    return Eigen::Vector4f(1, 0, 1, 1);
};