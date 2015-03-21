set(SOURCE_FILES main.cpp)
add_executable(raytracer ${SOURCE_FILES} Bedrock.cpp Bedrock.h)

# Find and link glfw3
target_link_libraries(raytracer GL glfw)

install(TARGETS raytracer DESTINATION ${Assignment3_SOURCE_DIR})