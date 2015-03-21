//
// Created by bacon on 3/20/15.
//

#include "Scene.h"
Scene::Scene(std::vector<Intersectable> geometry, Camera camera, SceneParameters parameters)
        : camera(camera),
          geometry(geometry),
          parameters(parameters){
}

std::vector<Intersectable*> Scene::Trace(std::vector<Ray> rays){
    // Naive ray trace!
    // i.e. compare every ray to every piece of geometry and return the closest intersecting one.
    std::vector<Intersectable*> output(rays.size(), nullptr);
    for(auto r = 0; r < rays.size(); r += 1){
        // Collide against intersectables ...
        auto best = std::make_tuple<float, Intersectable*>(std::numeric_limits<float>::infinity(), nullptr);
        for(auto g = 0; g < this->geometry.size(); g += 1){
            auto d = this->geometry[g].Intersect(rays[r]);
            if(d != 0.0f && d < std::get<0>(best)){
                std::get<0>(best) = d;
                std::get<1>(best) = &(this->geometry[g]);
            }
        }
    }
}

std::tuple<std::vector<uint8_t>, std::chrono::milliseconds> Scene::Render(){
    auto start = std::chrono::high_resolution_clock::now();
    State state = {0}; // Scary. Very scary.
    state.Complete = false;
    while(!state.Complete) {
        this->Render(state);
        auto rays = state.Primary;
        state.PrimaryIntersections = this->Trace(rays);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    return std::make_tuple(state.Frame, std::chrono::duration_cast<std::chrono::milliseconds>(finish- start));
}

void Scene::Render(Scene::State& state){
    // If there aren't any primary rays, create them.
    if(state.Primary.size() == 0){
        state.Primary = this->camera.Cast();
    }

    // Now that you have primary intersections, draw their colours!
    if(state.PrimaryIntersections.size() > 0){
        state.Frame = std::vector<uint8_t>(state.PrimaryIntersections.size());
        for(auto i = 0; i < state.PrimaryIntersections.size(); i += 1){
            if(state.PrimaryIntersections[i] == nullptr) continue;
            auto colour = state.PrimaryIntersections[i]->Colour(state.Primary[i]);
            state.Frame[4*i] = std::get<0>(colour);
            state.Frame[4*i+1] = std::get<1>(colour);
            state.Frame[4*i+2] = std::get<2>(colour);
            state.Frame[4*i+3] = std::get<3>(colour);
        }
        state.Complete = true;
    }
}