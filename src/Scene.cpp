//
// Created by bacon on 3/20/15.
//

#include "Scene.h"
Scene::Scene(std::vector<Intersectable> geometry, Camera camera, SceneParameters parameters)
        : camera(camera),
          geometry(geometry),
          parameters(parameters){
}

std::tuple<std::vector<uint8_t>, std::chrono::milliseconds> Scene::Render(){
    auto start = std::chrono::high_resolution_clock::now();
    State state{};
    this->Render(state);
    auto finish = std::chrono::high_resolution_clock::now();
    return std::make_tuple(state.Frame, std::chrono::duration_cast<std::chrono::milliseconds>(finish- start));
}

void Scene::Render(Scene::State& state){
    // Render the scene :O
    std::vector<uint8_t> whiteBuffer;
    for(auto i = 0; i < this->camera.width*this->camera.height*3; i += 1){
        whiteBuffer.push_back(255);
    }
    state.Frame = whiteBuffer;
}