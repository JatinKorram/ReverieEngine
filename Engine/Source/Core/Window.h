#pragma once
#include "Engine/Source/ReveriePCH.h"

namespace Reverie
{
    struct WindowInfo
    {
        enum WindowType
        {
            WINDOW_UNKNOWN,
            WINDOW_GLFW
        };

        WindowType Type;
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowInfo(WindowType t_Type = WINDOW_UNKNOWN,
                   const std::string& t_Title = "Reverie Application",
                   uint32_t t_Width = 640,
                   uint32_t t_Height = 480)
            : Type(t_Type), Title(t_Title), Width(t_Width), Height(t_Height)
        {
        }
    };

    class Window
    {
        public:
            static std::unique_ptr<Window> Create(const WindowInfo& t_Info);

            virtual ~Window() = default;

            virtual void Update() const = 0;

            virtual inline const void* GetNativeWindow() const = 0;
            virtual inline const WindowInfo& GetInfo() const = 0;
    };
}
