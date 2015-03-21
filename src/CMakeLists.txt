set(SOURCE_FILES main.cpp)
add_executable(raytracer ${SOURCE_FILES} Bedrock.cpp Bedrock.h Intersectable.h Ray.cpp Ray.h Sphere.cpp Sphere.h Scene.cpp Scene.h Camera.cpp Camera.h global.h SceneParameters.cpp SceneParameters.h Intersectable.cpp)

# Find and link glfw3
target_link_libraries(raytracer GL glfw)

install(TARGETS raytracer DESTINATION ${Assignment3_SOURCE_DIR})