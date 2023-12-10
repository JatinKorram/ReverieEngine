#pragma once
#include "Engine/Source/Core/Window.h"

struct GLFWwindow;

namespace Reverie
{
    class GLFWWindow : public Window
    {
        public:
            GLFWWindow(const WindowSpecification& t_Spec);
            ~GLFWWindow();

            virtual void Update() const override;

            virtual inline const void* GetNativeWindow() const override { return m_NativeWindow; }
            virtual inline const WindowSpecification& GetSpecification() const override { return m_Specification; }
        private:
            GLFWwindow* m_NativeWindow;
            WindowSpecification m_Specification;
    };
}
