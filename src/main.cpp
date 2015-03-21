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
    float offset = -5.0f;
    float ratio = 1.0f/100.0f;
    Bedrock rock(width, height, ratio, offset);
    auto camera = rock.GetCamera();
    SceneParameters parameters;

    std::vector<Intersectable*> geometry;
    Sphere sph(Eigen::Vector4f(0.0f, 1.0f, 12.0f, 0.0f), 10.0f);
    geometry.push_back(&sph);

    std::vector<Light> lights;
    Light lht(Eigen::Vector4f(-20.0f, 3.0f, 2.0f, 0.0f), Eigen::Vector4f(1.0f, 1.0f, 1.0f, 1.0f), 255);
    lights.push_back(lht);

    Scene scene(geometry, lights, camera, parameters);
    auto result = scene.Render();
    std::chrono::duration<float> seconds = std::get<1>(result);
    std::cout << "Frame render time (ms): " << seconds.count() << std::endl;
    auto whiteBuffer = std::get<0>(result);
    rock.Draw(whiteBuffer);
    rock.RunForever();
    return 0;
}