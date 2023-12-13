#include "Engine/Source/Drivers/GLFW/GLFWWindow.h"
#include "Engine/Source/Core/Application.h"
#include "GLFW/glfw3.h"

namespace Reverie
{
    GLFWWindow::GLFWWindow(const WindowInfo& t_Info)
        : m_NativeWindow(nullptr), m_Info(t_Info)
    {
        if (glfwInit() != GLFW_TRUE)
        {
            return;
        }

        m_NativeWindow = glfwCreateWindow(t_Info.Width, t_Info.Height, t_Info.Title.c_str(), nullptr, nullptr);
        if (!m_NativeWindow)
        {
            glfwTerminate();
            return;
        }
    }

    GLFWWindow::~GLFWWindow()
    {
        glfwDestroyWindow(m_NativeWindow);
        glfwTerminate();
    }

    void GLFWWindow::Update() const
    {
        if (glfwWindowShouldClose(m_NativeWindow))
            Application::GetInstance()->Quit();

        glfwPollEvents();
    }
}
