#include <iostream>
#include "Bedrock.h"
#include "Scene.h"
#include "Eigen/Dense"
#include "Sphere.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    float width = 640.0f;
    float height = 480.0f;
    float offset = -20.0f;
    float ratio = 1.0f/2.0f;
    Bedrock rock(width, height, ratio, offset);
    auto camera = rock.GetCamera(50);
    SceneParameters parameters;
    std::vector<Intersectable> geometry;
    geometry.push_back(Sphere(Eigen::Vector4f(0.0f, 0.0f, 0.0f, 0.0f), 5.0f));
    Scene scene(geometry, camera, parameters);
    auto result = scene.Render();
    std::chrono::duration<float> seconds = std::get<1>(result);
    std::cout << "Frame render time (ms): " << seconds.count() << std::endl;
    auto whiteBuffer = std::get<0>(result);
    rock.Draw(whiteBuffer);
    rock.RunForever();
    return 0;
}