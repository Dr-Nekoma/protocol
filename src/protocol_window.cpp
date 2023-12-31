#include "protocol_window.hpp"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan_core.h"
#include <stdexcept>

namespace protocol {
    
    ProtocolWindow::ProtocolWindow(int width, int height, std::string windowName): width{width}, height{height}, windowName{windowName}{
        initWindow();
    }

    ProtocolWindow::~ProtocolWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void ProtocolWindow::initWindow(){
        glfwInit();
        // No OpenGL, Vulkan instead
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    
    }

    void ProtocolWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface){
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
            throw std::runtime_error("Failed to create window surface");
    }
}