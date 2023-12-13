#pragma once
#include "Engine/Source/ReveriePCH.h"

namespace Reverie
{
    struct RenderingContextInfo
    {
        enum ContextType
        {
            CONTEXT_UNKNOWN,
            CONTEXT_VULKAN
        };

        ContextType Type;

        RenderingContextInfo(ContextType t_Type = CONTEXT_UNKNOWN)
            : Type(t_Type)
        {
        }
    };

    class RenderingContext
    {
        public:
            static std::unique_ptr<RenderingContext> Create(const RenderingContextInfo& t_Info);

            virtual ~RenderingContext() = default;

            virtual inline const RenderingContextInfo& GetInfo() const = 0;
    };
}
