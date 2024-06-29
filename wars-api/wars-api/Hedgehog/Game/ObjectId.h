#pragma once

namespace hh::game {
    struct ObjectId {
        uint32_t id{};

        inline bool operator==(const ObjectId& other) const {
            return id == other.id;
        }

        inline bool operator!=(const ObjectId& other) const {
            return !operator==(other);
        }

        inline bool IsNonNull() const {
            return id != 0;
        }
    };
}
