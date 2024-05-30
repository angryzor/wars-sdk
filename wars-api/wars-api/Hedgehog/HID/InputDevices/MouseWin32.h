#pragma once

namespace hh::hid {
    class MouseWin32 : public Mouse, public hh::fw::MouseEventHandler {
    public:
        uint32_t unk101;
        MouseWin32();
        static MouseWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Update() override;
        virtual void SetCursorPos() override;
        virtual void UpdateMouseState(MouseState& mouseState) const override;
    };
}
