#include <iostream>
#include "Bedrock.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int width = 640;
    int height = 480;
    Bedrock rock(width, height);
    std::vector<uint8_t> whiteBuffer;
    for(auto i = 0; i < width*height*3; i += 1){
        whiteBuffer.push_back(255);
    }
    rock.Draw(whiteBuffer);
    rock.RunForever();
    return 0;
}