#pragma once

namespace hh::hid {
    class ActionMapping : public fnd::ReferencedObject {
        struct Binding {
            uint32_t inputId;
        };

        uint8_t unk1;
        bool unk2;
        csl::ut::VariableString name;
        csl::ut::MoveArray<Binding> bindings;
    public:
        CREATE_FUNC(ActionMapping, const char* name);
        void BindInput(uint32_t inputId);
    };

    class AxisMapping : public fnd::ReferencedObject {
        struct Binding {
            uint32_t inputId;
            float limit;
            float treshold;
        };

        uint8_t unk1;
        csl::ut::VariableString name;
        csl::ut::MoveArray<Binding> bindings;
    public:
        CREATE_FUNC(AxisMapping, const char* name);
        void BindInput(uint32_t inputId, float limit);
        void BindInputEx(uint32_t inputId, float limit, float threshold);
    };

    class InputMapSettings : public fnd::ReferencedObject {
        csl::ut::MoveArray<ActionMapping*> actionMappings;
        csl::ut::MoveArray<AxisMapping*> axisMappings;
        uint32_t maxMappingUnk1PlusOne;
        float unk4; // in musashi default 0.4
        float unk5; // in musashi default 0.15

    public:
        DEFAULT_CREATE_FUNC(InputMapSettings);

        int FindActionMappingId(const char* name);
        int FindAxisMappingId(const char* name);

        void BindActionMapping(const char* mappingName, uint32_t inputId);
        void BindAxisMapping(const char* mappingName, uint32_t inputId, float limit);
        void BindAxisMappingEx(const char* mappingName, uint32_t inputId, float limit, float threshold);
        
        uint8_t GetActionMappingUnk1(int actionMappingId);
        uint8_t GetAxisMappingUnk1(int axisMappingId);
        void SetActionMappingUnk1(const char* mappingName, uint8_t value);
        void SetActionMappingUnk2(const char* mappingName, bool value);
    };

    class InputMap : public fnd::ReferencedObject {
    public:
        struct Config {
            InputMapSettings* settings;
            csl::ut::InplaceMoveArray<InputDevice*, 10> devices;
            uint32_t unk3;
        public:
            Config();
            void AddDevice(InputDevice* device);
        };

    private:
        InputMapSettings* settings;
        csl::ut::InplaceMoveArray<InputDevice*, 5> devices;
        csl::ut::MoveArray<void*> actionMaps;
        csl::ut::MoveArray<void*> axisMaps;
        csl::ut::MoveArray<void*> unk5;
        uint32_t unk6;
        float unk7; // the 2 floats from the settings
        float unk8;
        uint32_t unk9; // unk3 from config

    public:
        CREATE_FUNC(InputMap, Config& config);
    };
}
