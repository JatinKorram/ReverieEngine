#pragma once
#include "Engine/Source/ReveriePCH.h"

namespace Reverie
{
    class Window;

    struct ApplicationInfo
    {
        inline static uint32_t MakeVersion(uint8_t t_Major, uint8_t t_Minor, uint8_t t_Patch) { return ((uint32_t)t_Major << 16) | ((uint32_t)t_Minor << 8) | (uint32_t)t_Patch; }

        std::string Name;
        uint32_t Version;

        ApplicationInfo(const std::string& t_Name = "Reverie Application",
                        const uint32_t t_Version = 0)
            : Name(t_Name), Version(t_Version)
        {
        }
    };

    // REVIEW: Should we add a static Create() function here as
    //         well for consistency?
    // REVIEW: We should also add a way to log errors and stuff.
    class Application
    {
        public:
            Application(const ApplicationInfo& t_Info);
            ~Application();

            void Run();
            void Quit();

            inline static Application* GetInstance() { return s_Instance; }
            inline const std::unique_ptr<Window>& GetWindow() const { return m_Window; }
            inline const ApplicationInfo& GetInfo() const { return m_Info; }
        private:
            static Application* s_Instance;
            ApplicationInfo m_Info;
            bool m_IsRunning;
            std::unique_ptr<Window> m_Window;
    };
}