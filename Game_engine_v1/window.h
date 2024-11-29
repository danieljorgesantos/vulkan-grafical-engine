#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

namespace Window {

extern const uint32_t WIDTH;
extern const uint32_t HEIGHT;

extern GLFWwindow* window;

struct WindowContext {
    bool framebufferResized = false;
    double lastMouseX = 0.0;
    double lastMouseY = 0.0;
    bool firstMouse = true;  // Track initial mouse movement
};

extern WindowContext context;

void initialize();
void cleanup();
void keyCallback(GLFWwindow* window, int key, int scancode, int action,
                 int mods);

}  // namespace Window

#endif  // WINDOW_H
