#include "Engine/Source/Core/Window.h"
#include "Engine/Source/Drivers/GLFW/GLFWWindow.h"

namespace Reverie
{
    std::unique_ptr<Window> Window::Create(const WindowSpecification& t_Spec)
    {
        switch (t_Spec.Type)
        {
            case WindowSpecification::WINDOW_GLFW:  return std::make_unique<GLFWWindow>(t_Spec);
        }
        return nullptr;
    }
}
