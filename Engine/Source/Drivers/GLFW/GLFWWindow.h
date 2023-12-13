#pragma once
#include "Engine/Source/Core/Window.h"

struct GLFWwindow;

namespace Reverie
{
    class GLFWWindow : public Window
    {
        public:
            GLFWWindow(const WindowInfo& t_Info);
            ~GLFWWindow();

            virtual void Update() const override;

            virtual inline const void* GetNativeWindow() const override { return m_NativeWindow; }
            virtual inline const WindowInfo& GetInfo() const override { return m_Info; }
        private:
            WindowInfo m_Info;
            GLFWwindow* m_NativeWindow;
    };
}
