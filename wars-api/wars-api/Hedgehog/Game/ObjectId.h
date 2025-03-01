#pragma once
#include <ucsl/object-id.h>

namespace hh::game {
    struct ObjectId : public ucsl::objectids::ObjectIdV1 {
		inline ObjectId(const ucsl::objectids::ObjectIdV1& other) : ucsl::objectids::ObjectIdV1{ other } {}
		inline ObjectId(ucsl::objectids::ObjectIdV1&& other) : ucsl::objectids::ObjectIdV1{ std::move(other) } {}

        ObjectId() = default;
        ObjectId(unsigned int id) : ucsl::objectids::ObjectIdV1{ id } {}
        ObjectId(const ObjectId& other) = default;

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
