#pragma once

namespace hh::game {
    class WorldObjectStatus {
    public:
        // This is all very speculative
        enum class Flag : uint8_t {
            ENABLED,
            IS_ALIVE,
            SHUTDOWN,
            NO_RESTART,
        };

        ObjectData* objectData;
        csl::ut::Bitset<Flag> flags;
        uint32_t state;
        virtual ~WorldObjectStatus() = default;

        inline bool IsShutdown() {
            return flags.test(Flag::SHUTDOWN);
        }

        inline bool IsNoRestart() {
            return flags.test(Flag::NO_RESTART);
        }

        inline void Shutdown() {
            flags.set(Flag::SHUTDOWN);
        }

        inline void Restart() {
            flags.reset(Flag::SHUTDOWN);
        }

        inline uint16_t GetObjectState(unsigned int stateId) {
            return (this->state & (0xFFFF << (16 * stateId))) >> (16 * stateId);
        }

        inline void SetObjectState(unsigned int stateId, uint16_t state) {
            this->state = this->state & ~(0xFFFF << (16 * stateId)) | (0xFFFF << (16 * stateId)) & (state << (16 * stateId));
        }
    };
}
