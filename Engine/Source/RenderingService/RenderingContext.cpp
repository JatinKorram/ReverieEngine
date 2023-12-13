#include "Engine/Source/RenderingService/RenderingContext.h"
#include "Engine/Source/Drivers/Vulkan/VulkanRenderingContext.h"

namespace Reverie
{
    std::unique_ptr<RenderingContext> RenderingContext::Create(const RenderingContextInfo& t_Info)
    {
        switch (t_Info.Type)
        {
            case RenderingContextInfo::CONTEXT_VULKAN:  return std::make_unique<VulkanRenderingContext>(t_Info);
        }
        return nullptr;
    }
}