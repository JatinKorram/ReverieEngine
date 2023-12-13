#include "Engine/Source/Core/Window.h"
#include "Engine/Source/Drivers/GLFW/GLFWWindow.h"

namespace Reverie
{
    std::unique_ptr<Window> Window::Create(const WindowInfo& t_Info)
    {
        switch (t_Info.Type)
        {
            case WindowInfo::WINDOW_GLFW:   return std::make_unique<GLFWWindow>(t_Info);
        }
        return nullptr;
    }
}
