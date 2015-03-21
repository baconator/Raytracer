#include <iostream>
#include "Bedrock.h"
#include "Scene.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int width = 640;
    int height = 480;
    Bedrock rock(width, height);
    auto camera = rock.GetCamera(50);
    SceneParameters parameters;
    Scene scene(std::vector<Intersectable>(), camera, parameters);
    auto whiteBuffer = std::get<0>(scene.Render());
    rock.Draw(whiteBuffer);
    rock.RunForever();
    return 0;
}