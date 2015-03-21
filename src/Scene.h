//
// Created by bacon on 3/20/15.
//

#ifndef _ASSIGNMENT3_SCENE_H_
#define _ASSIGNMENT3_SCENE_H_
#include "Intersectable.h"
#include "Ray.h"
#include "Camera.h"
#include "global.h"
#include "SceneParameters.h"
#include <vector>
#include <array>
#include <tuple>
#include <chrono>

class Scene {
public:
    struct State{
        bool Complete;
        std::vector<uint8_t> Frame;
        std::vector<Ray> Primary; // If there aren't any primary rays, generate them.
        std::vector<Intersectable*> PrimaryIntersections;

        std::vector<std::array<Ray, DIFFUSE_REFLECTION_RAYS>> Reflected;
        int ReflectedDepth; // Reflected rays are iterated upon as long as ReflectedDepth is valid.

        std::vector<Ray> Refracted; // 

        std::vector<Ray> Shadow;
    };
private:
    Camera camera;
    std::vector<Intersectable> geometry;
    SceneParameters parameters;
    void Render(State& state);
    std::vector<Intersectable*> Trace(std::vector<Ray> rays);

public:
    Scene(std::vector<Intersectable> geometry, Camera camera, SceneParameters parameters);
    std::tuple<std::vector<uint8_t>, std::chrono::milliseconds> Render();
};


#endif //_ASSIGNMENT3_SCENE_H_
