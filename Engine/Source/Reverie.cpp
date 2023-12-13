#include "Engine/Source/Core/Application.h"

int main()
{
    Reverie::ApplicationInfo info;
    info.Name = "Reverie Application";
    info.Version = Reverie::ApplicationInfo::MakeVersion(0, 0, 1);
    
    Reverie::Application app(info);
    app.Run();
}