#pragma once
#include "Engine/Source/ReveriePCH.h"

namespace Reverie
{
    struct RenderingContextSpecification
    {
        enum ContextType
        {
            CONTEXT_UNKNOWN,
            CONTEXT_VULKAN
        };

        ContextType Type;

        RenderingContextSpecification(ContextType t_Type = CONTEXT_UNKNOWN)
            : Type(t_Type)
        {
        }
    };

    class RenderingContext
    {
        public:
            static std::unique_ptr<RenderingContext> Create(const RenderingContextSpecification& t_Spec);

            virtual ~RenderingContext() = default;

            virtual inline const RenderingContextSpecification& GetSpecification() const = 0;
    };
}
