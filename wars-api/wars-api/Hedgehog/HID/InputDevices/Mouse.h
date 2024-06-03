#pragma once

namespace hh::hid {
    class Mouse : public InputDevice {
    public:
        struct MouseState {
            enum class ButtonStateFlag : unsigned short {
                LEFT,
                RIGHT,
                MIDDLE,
                MEDIA_UP,
                MEDIA_DOWN,
            };
            csl::ut::Bitset<ButtonStateFlag> buttonState;
            unsigned short deltaX;
            unsigned short deltaY;
            unsigned short unk1;
            unsigned short unk2;
            unsigned short cursorPosX;
            unsigned short cursorPosY;
            unsigned short prevCursorPosX;
            unsigned short prevCursorPosY;
        };

        MouseState state;
        bool hasUpdated;

        Mouse();
        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual float GetInputValue(unsigned int inputId) const override;
        virtual void Update() override;
        virtual bool HasUpdated() override;
        virtual void SetCursorPos() = 0;
        virtual void UpdateMouseState(MouseState& mouseState) const {}
    };
}
