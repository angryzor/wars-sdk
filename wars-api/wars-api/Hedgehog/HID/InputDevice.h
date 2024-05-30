#pragma once

namespace hh::hid {
    class InputDevice : public fnd::ReferencedObject {
    public:
        InputDevice();

        virtual void* GetRuntimeTypeInfo() const;
        virtual unsigned int GetDeviceId() const;
        virtual float GetInputValue() const;
        virtual csl::math::Vector4 UnkFunc3(); // most probably not a vector, but don't know what it really is
        virtual void Update() {}
        virtual bool UnkFunc6() { return true; }
        virtual bool HasUpdated() { return false; } 
        virtual bool UnkFunc7b() { return true; } 
    };
}
