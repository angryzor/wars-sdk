#pragma once

namespace hh::hid {
    class InputDevice : public fnd::ReferencedObject {
    public:
        InputDevice();

        virtual void* GetRuntimeTypeInfo() const;
        virtual unsigned int GetDeviceId() const;
        virtual float GetInputValue(unsigned int inputId) const;
        virtual csl::math::Vector4 GetTarget() const;
        virtual void Update() {}
        virtual bool UnkFunc6() { return true; }
        virtual bool HasUpdated() { return false; } 
        virtual bool UnkFunc7b() { return true; } 
    };
}
