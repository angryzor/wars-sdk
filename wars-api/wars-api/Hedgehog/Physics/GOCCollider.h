#pragma once

namespace hh::physics {
    class PhysicsWorld;

    struct ColliShape {
        enum Type : uint8_t {
            SPHERE,
            BOX,
            CAPSULE,
            CYLINDER,
        };

        struct SphereParameters {
            float radius;
        };

        struct BoxParameters {
            csl::math::Vector3 dimensions;
        };

        struct CapsuleParameters {
            float radius;
            float halfHeight;
        };

        struct CylinderParameters {
            float radius;
            float halfHeight;
        };

        union ColliShapeParameters {
            SphereParameters sphere;
            BoxParameters box;
            CapsuleParameters capsule;
            CylinderParameters cylinder;
        };

        Type type;
        ColliShapeParameters parameters;
    };

    class GOCCollider;
    class GOCColliderListener {
    public:
        virtual ~GOCColliderListener() = default;
        virtual void GOCCL_UnkFunc1(GOCCollider* collider) {}
        virtual void GOCCL_UnkFunc2(GOCCollider* collider) {}
        virtual void GOCCL_UnkFunc3(GOCCollider* collider) {}
    };

    class GOCCollider : public game::GOComponent, public fnd::HFrameListener {
    public:
        struct SetupInfo {
            enum class Flag : uint8_t {
                HAS_POSITION,
                HAS_ROTATION,
                HAS_SCALE,
            };

            ColliShape::Type shapeType;
            uint8_t unk2;
            csl::ut::Bitset<Flag> flags;
            uint16_t filterCategory;
            uint16_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;
            fnd::HFrame* frame2;
            csl::math::Transform transform;
            float unk9;
            float unk10;

            SetupInfo(ColliShape::Type shape);
            void SetPosition(csl::math::Vector3 position);
            void SetRotation(csl::math::Quaternion rotation);
            void SetScale(csl::math::Vector3 scale);
        };

        enum class Flag : uint8_t {
            ENABLED,
            FRAME_DIRTY,
        };

        uint64_t unk101;
        fnd::HFrame* frame;
        fnd::HFrame* frame2;
        csl::math::Matrix34 worldTransform;
        csl::math::Matrix34 localTransform;
        ColliShape::Type shapeType;
        uint8_t unk104b;
        uint8_t filterCategory;
        csl::ut::Bitset<Flag> flags;
        uint16_t unk105b;
        uint64_t unk106;
        uint32_t unk107;
        PhysicsWorld* physicsWorld;
        csl::ut::InplaceMoveArray<void*, 1> unk109; // incorrect, the inner obj here is actually 2 floats
        uint64_t unk111;

        GOCCollider(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual const char* GetCategory() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void GetShape(ColliShape& shape) const = 0;

        void Setup(const SetupInfo& setupInfo);
        void AddListener(GOCColliderListener* listener);
        void RemoveListener(GOCColliderListener* listener);
        void SetEnabled(bool enabled);

        inline csl::math::Matrix34 GetWorldTransform() const { return worldTransform; };
        inline csl::math::Matrix34 GetLocalTransform() const { return localTransform; };

        GOCOMPONENT_CLASS_DECLARATION(GOCCollider);
    };
}
