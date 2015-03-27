#include <iostream>
#include "Bedrock.h"
#include "Scene.h"
#include "Eigen/Dense"
#include "Sphere.h"
#include "MaterialParameters.h"

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

    Eigen::Vector4f pink(1.0f, 0.3f, 1.0f, 1.0f);
    MaterialParameters matParams{pink, pink, pink, 0.0f};
    Eigen::Vector4f blue(0.3f, 0.3f, 1.0f, 1.0f);
    MaterialParameters matParams2{blue, blue, blue, 5.0f};

    std::vector<Intersectable*> geometry;
    Sphere sph2(Eigen::Vector4f(-2.0f, 0.0f, 5.0f, 0.0f), 3.0f, matParams2);
    Sphere sph(Eigen::Vector4f(0.0f, 1.0f, 12.0f, 0.0f), 10.0f, matParams);
    geometry.push_back(&sph);
    geometry.push_back(&sph2);

    std::vector<Light> lights;
    Light lht(Eigen::Vector4f(10.0f, 1.0f, 3.0f, 0.0f), Eigen::Vector4f(1.0f, 1.0f, 1.0f, 1.0f));
    lights.push_back(lht);

    Scene scene(geometry, lights, camera, parameters);
    auto result = scene.Render();
    std::chrono::duration<float> milliseconds = std::get<1>(result);
    std::cout << "Frame render time (ms): " << milliseconds.count() << std::endl;
    auto whiteBuffer = std::get<0>(result);
    rock.Draw(whiteBuffer);
    rock.RunForever();
    return 0;
}