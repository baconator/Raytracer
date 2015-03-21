//
// Created by bacon on 3/20/15.
//

#include "Bedrock.h"
#include <iostream>
// So that this doesn't occupy all of the rams
#include <thread>

void Bedrock::InitializeGlfw(int width, int height){
    // Initialize GLFW, get a window instance.
    if(!glfwInit())
        throw -1;

    glfwSetErrorCallback([](auto error, auto description){
        std::cout << "Error (" << error << "): " << description << std::endl;
    });

    this->window = glfwCreateWindow(width, height, "Raytracer 0.0.1", NULL, NULL);
    if(!this->window)
        throw -1;

    glfwMakeContextCurrent(this->window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(this->window, [](auto window, auto key, auto scancode, auto action, auto mods){
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
    });
}


Bedrock::Bedrock(float width, float height, float screenToWorldRatio, float offset):
        dirty(false),
        width(width),
        height(height),
        screenToWorldRatio(screenToWorldRatio),
        offset(offset),
        displayed(std::vector<uint8_t>{}){
    this->InitializeGlfw(width, height);
    // GLFW is all set up, now.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // And now we have transparency!
}

void Bedrock::Draw(std::vector<uint8_t> frame){
    this->displayed.clear();
    this->displayed = frame;
    this->dirty = true;
}

void Bedrock::RunForever(){
    while(!glfwWindowShouldClose(this->window)){
        if(dirty) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glDrawPixels(this->width, this->height, GL_RGBA, GL_UNSIGNED_BYTE, &(this->displayed[0]));
            glfwSwapBuffers(this->window);
            this->dirty = false;
        }
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

Camera Bedrock::GetCamera(){
    return Camera(this->width, this->height, this->screenToWorldRatio, this->offset);
}