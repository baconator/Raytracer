//
// Created by bacon on 3/20/15.
//

// Included for the frame type
#include <cstdint>
#include <vector>

// Unique pointers (and functional for the deleter)!
#include <memory>
#include <functional>

// You need GLFW, of course.
#include <GLFW/glfw3.h>
#include "Camera.h"

#ifndef _ASSIGNMENT3_BEDROCK_H_
#define _ASSIGNMENT3_BEDROCK_H_


class Bedrock {
private:
    GLFWwindow* window;
    void InitializeGlfw(int width, int height);
    std::vector<uint8_t> displayed;
    bool dirty;
    float width;
    float height;
    float screenToWorldRatio;
    float offset;
public:
    Bedrock(float width, float height, float screenToWorldRatio, float offset);
    void Draw(std::vector<uint8_t> frame);
    Camera GetCamera();

    // Runs in a loop until the escape key is pressed.
    void RunForever();
};


#endif //_ASSIGNMENT3_BEDROCK_H_
