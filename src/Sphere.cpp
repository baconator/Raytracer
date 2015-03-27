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

    auto ambientProduct = this->material.ambientReflectance.cwiseProduct(ambient);
    Eigen::Vector4f I = ambientProduct;
    #pragma clang loop vectorize(enable)
    for(auto& light : lights){
        auto L = (x-light.position).normalized();
        // http://en.wikipedia.org/wiki/Specular_reflection#Direction_of_reflection
        auto diffuseProduct = this->material.diffuseReflectance.cwiseProduct((L.dot(N))*light.colour);
        auto R = 2*(N.dot(L))*N-L;
        auto specularProduct = this->material.specularReflectance.cwiseProduct(pow(R.dot(V), this->material.shininess)*light.colour);
        I += static_cast<Eigen::Vector4f>(diffuseProduct + specularProduct);
    }

    if(I.minCoeff() <= 0.0f){
        return Eigen::Vector4f(0, 0, 0, 1.0);
    }else {
        return I;
    }
};