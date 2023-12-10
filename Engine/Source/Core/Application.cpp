#include "Engine/Source/Core/Application.h"
#include "Engine/Source/Core/Window.h"

namespace Reverie
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
        : m_IsRunning(false), m_Window(nullptr)
    {
        s_Instance = this;

        {
            WindowSpecification spec;
            spec.Type = WindowSpecification::WINDOW_GLFW;
            m_Window = Window::Create(spec);
        }
    }

    Application::~Application()
    {
        s_Instance = nullptr;
    }

    void Application::Run()
    {
        m_IsRunning = true;
        while (m_IsRunning)
        {
            m_Window->Update();
        }
    }

    void Application::Quit()
    {
        m_IsRunning = false;
    }
}
