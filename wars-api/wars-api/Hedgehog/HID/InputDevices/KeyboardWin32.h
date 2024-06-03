#pragma once

namespace hh::hid {
    class KeyboardWin32 : public Keyboard {
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
        char unk104[1024];
        char unk105[1024];
        csl::ut::MoveArray<void*> unk106;
        uint64_t unk107;
        uint64_t unk108;
    public:
        KeyboardWin32(csl::fnd::IAllocator* pAllocator);
        static KeyboardWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual float GetInputValue(unsigned int inputId) const override;
        virtual const char* UnkFunc8() override;
        virtual void UpdateKeyboardState(bool (&state)[256]) const override;
        virtual unsigned int UnkFunc10() override;
    };
}
