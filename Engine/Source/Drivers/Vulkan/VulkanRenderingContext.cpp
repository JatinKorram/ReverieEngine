#include "Engine/Source/Drivers/Vulkan/VulkanRenderingContext.h"
#include "Engine/Source/Core/Application.h"
#include "Engine/Source/Core/Window.h"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan.h"

namespace Reverie
{
    VulkanRenderingContext::VulkanRenderingContext(const RenderingContextInfo& t_Info)
        : m_Info(t_Info), m_VulkanInstance(nullptr)
    {
        const ApplicationInfo app_info =  Application::GetInstance()->GetInfo();

        VkApplicationInfo vk_app_info;
        vk_app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        vk_app_info.pApplicationName = app_info.Name.c_str();
        vk_app_info.applicationVersion = app_info.Version;
        vk_app_info.pEngineName = RV_ENGINE_NAME;
        vk_app_info.engineVersion = VK_MAKE_API_VERSION(0, RV_ENGINE_VERSION_MAJOR, RV_ENGINE_VERSION_MINOR, RV_ENGINE_VERSION_PATCH);
        vk_app_info.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo vk_instance_info;
        vk_instance_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        vk_instance_info.pApplicationInfo = &vk_app_info;
        vk_instance_info.ppEnabledExtensionNames = glfwGetRequiredInstanceExtensions(&vk_instance_info.enabledExtensionCount);
        vk_instance_info.enabledLayerCount = 0;

        vkCreateInstance(&vk_instance_info, nullptr, &m_VulkanInstance);
    }

    VulkanRenderingContext::~VulkanRenderingContext()
    {
        vkDestroyInstance(m_VulkanInstance, nullptr);
    }
}
