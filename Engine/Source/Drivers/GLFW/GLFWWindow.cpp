#include "Engine/Source/Drivers/GLFW/GLFWWindow.h"
#include "Engine/Source/Core/Application.h"
#include "GLFW/glfw3.h"

namespace Reverie
{
    GLFWWindow::GLFWWindow(const WindowSpecification& t_Spec)
        : m_NativeWindow(nullptr), m_Specification(t_Spec)
    {
        if (glfwInit() != GLFW_TRUE)
        {
            return;
        }

        m_NativeWindow = glfwCreateWindow(t_Spec.Width, t_Spec.Height, t_Spec.Title.c_str(), nullptr, nullptr);
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
