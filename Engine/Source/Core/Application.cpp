#include "Engine/Source/Core/Application.h"
#include "Engine/Source/Core/Window.h"

namespace Reverie
{
    Application* Application::s_Instance = nullptr;

    Application::Application(const ApplicationInfo& t_Info)
        : m_Info(t_Info), m_IsRunning(false), m_Window(nullptr)
    {
        s_Instance = this;

        {
            WindowInfo info;
            info.Type = WindowInfo::WINDOW_GLFW;
            info.Title = t_Info.Name;
            m_Window = Window::Create(info);
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
