#pragma once

namespace hh::hid {
    class Keyboard : public InputDevice {
    public:
        csl::ut::InplaceMoveArray<uint32_t, 16> unk3;
        bool keyboardState[256];
        uint8_t unk6;

        Keyboard(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual float GetInputValue(unsigned int inputId) const override;
        virtual void Update() override;
        virtual bool HasUpdated() override;
        virtual const char* UnkFunc8();
        virtual void UpdateKeyboardState(bool (&state)[256]) const = 0;
        virtual unsigned int UnkFunc10() { return false; };
    };
}
