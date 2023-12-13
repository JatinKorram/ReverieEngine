#pragma once
#include "Engine/Source/RenderingService/RenderingContext.h"

struct VkInstance_T;
typedef VkInstance_T* VkInstance;

namespace Reverie
{
    // TODO: Add the many other rendering context functions
    class VulkanRenderingContext : public RenderingContext
    {
        public:
            VulkanRenderingContext(const RenderingContextInfo& t_Info);
            ~VulkanRenderingContext();

            virtual inline const RenderingContextInfo& GetInfo() const override { return m_Info; }
        private:
            RenderingContextInfo m_Info;
            VkInstance m_VulkanInstance;
    };
}
