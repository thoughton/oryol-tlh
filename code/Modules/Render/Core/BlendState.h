#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::Render::BlendState
    @brief describe alpha blending state
*/
#include "Core/Types.h"
#include "Render/Core/Enums.h"

namespace Oryol {
namespace Render {
    
class BlendState {
public:
    union {
        struct {
            bool BlendEnabled:1;
            BlendFactor::Code SrcFactorRGB:5;
            BlendFactor::Code DstFactorRGB:5;
            BlendOperation::Code OpRGB:3;
            BlendFactor::Code SrcFactorAlpha:5;
            BlendFactor::Code DstFactorAlpha:5;
            BlendOperation::Code OpAlpha:3;
            Channel::Mask ColorWriteMask:4;
        };
        /// hash code from merged state
        uint32 Hash;
    };

    /// constructor
    BlendState() {
        this->Hash = 0;
        this->BlendEnabled = false;
        this->SrcFactorRGB = BlendFactor::One;
        this->DstFactorRGB = BlendFactor::Zero;
        this->OpRGB = BlendOperation::Add;
        this->SrcFactorAlpha = BlendFactor::One;
        this->DstFactorAlpha = BlendFactor::Zero;
        this->OpAlpha = BlendOperation::Add;
        this->ColorWriteMask = Channel::RGBA;
    };
    
    /// equality
    bool operator==(const BlendState& rhs) const {
        return this->Hash == rhs.Hash;
    };
    /// inequality
    bool operator!=(const BlendState& rhs) const {
        return this->Hash != rhs.Hash;
    };
};

} // namespace Render
} // namespace Oryol