//
// Created by bacon on 3/20/15.
//

#include "Scene.h"
Scene::Scene(std::vector<Intersectable*> geometry, std::vector<Light> lights, Camera camera, SceneParameters parameters)
        : camera(camera),
          geometry(geometry),
          lights(lights),
          parameters(parameters){
}

std::vector<Intersectable*> Scene::Trace(std::vector<Ray>& rays){
    // Naive ray trace!
    // i.e. compare every ray to every piece of geometry and return the closest intersecting one.
    std::vector<Intersectable*> output(rays.size(), nullptr);
    for(auto r = 0; r < rays.size(); r += 1){
        // Collide against intersectables ...
        auto best = std::make_tuple<float, Intersectable*>(std::numeric_limits<float>::infinity(), nullptr);
        for(auto g = 0; g < this->geometry.size(); g += 1){
            auto d = this->geometry[g]->Intersect(rays[r]);
            if(d != 0.0f && d < std::get<0>(best)){
                std::get<0>(best) = d;
                std::get<1>(best) = this->geometry[g];
            }
        }
        output[r] = std::get<1>(best);
    }
    return output;
}

std::tuple<std::vector<uint8_t>, std::chrono::milliseconds> Scene::Render(){
    auto start = std::chrono::high_resolution_clock::now();
    State state = {0}; // Scary. Very scary.
    state.Complete = false;
    while(!state.Complete) {
        this->Render(state);
        state.PrimaryIntersections = this->Trace(state.Primary);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    return std::make_tuple(state.Frame, std::chrono::duration_cast<std::chrono::milliseconds>(finish-start));
}

void Scene::Render(Scene::State& state){
    // If there aren't any primary rays, create them.
    if(state.Primary.size() == 0){
        state.Primary = this->camera.Cast();
    }

    // Now that you have primary intersections, draw their colours!
    if(state.PrimaryIntersections.size() > 0){
        // Normalize out colour values.
        Eigen::Vector4f maxes(0, 0, 0, 0); // Yes, it normalizes transparency too.
        // TODO: do dynamic compression.
        // TODO: pass in ambient lighting properly.
        auto ambient = Eigen::Vector4f(1.0f, 1.0f, 1.0f, 1.0f);
        std::vector<Eigen::Vector4f> colours;
        for(auto i = 0; i < state.PrimaryIntersections.size(); i += 1){
            // If there are no intersections, return a transparent black. Otherwise, get the intersection colour.
            auto colour = (state.PrimaryIntersections[i] == nullptr)
                    ? Eigen::Vector4f(0.0f, 0.0f, 0.0f, 0.0f)
                    : state.PrimaryIntersections[i]->Colour(state.Primary[i], this->lights, ambient);
            colours.push_back(colour);
            maxes = colour.cwiseMax(maxes);
        }
        maxes[3] = 0.0f; // We're ignoring alpha for the max terms.
        auto upper = maxes.maxCoeff();

        state.Frame = std::vector<uint8_t>(state.PrimaryIntersections.size()*4, 0);
        for(auto i = 0; i < colours.size(); i += 1){
            if(state.PrimaryIntersections[i] == nullptr) continue;
            auto colour = colours[i];
            state.Frame[4*i] = static_cast<uint8_t>(round(colour[0]/ upper *255.0f));
            state.Frame[4*i+1] = static_cast<uint8_t>(round(colour[1]/ upper *255.0f));
            state.Frame[4*i+2] = static_cast<uint8_t>(round(colour[2]/ upper *255.0f));
            state.Frame[4*i+3] = static_cast<uint8_t>(round(255.0f));
        }
        state.Complete = true;
    }
}