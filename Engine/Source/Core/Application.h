#pragma once
#include "Engine/Source/ReveriePCH.h"

namespace Reverie
{
    class Window;

    class Application
    {
        public:
            Application();
            ~Application();

            void Run();
            void Quit();

            static Application* GetInstance() { return s_Instance; }
        private:
            static Application* s_Instance;
            bool m_IsRunning;
            std::unique_ptr<Window> m_Window;
    };
}