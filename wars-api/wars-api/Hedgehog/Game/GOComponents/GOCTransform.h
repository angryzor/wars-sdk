#pragma once

namespace hh::game {
    class GOCTransform : public GOComponent {
        uint64_t unk1;
        uint64_t unk2;
        csl::ut::LinkListNode node;
        GOCTransform* parent;
        csl::ut::LinkList<GOCTransform> children;
        csl::math::Transform transform;
        fnd::HFrame frame;
    public:
        char unk9;
        char unk10;
        char gocTransformFlags;
        uint32_t unk12;

        enum class Flag : unsigned char {
            TRANSFORM_POSITION = 1,
            TRANSFORM_ROTATION = 2,
        };

        struct alignas(8) Config {
        };

        DEFAULT_CREATE_FUNC(GOCTransform);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Initialize(const Config& config);
        void SetInheritedFlags(Flag flags);
        void SetLocalTransform(const csl::math::Transform& transform);
        void SetLocalTranslation(const csl::math::Vector3& position);
        void SetLocalRotation(const csl::math::Quaternion& rotation);
        void SetLocalTranslationAndRotation(const csl::math::Vector3& position, const csl::math::Quaternion& rotation);
        void SetParent(GOCTransform* parent);
        bool IsExistParent();
        
        inline GOCTransform* GetParent() {
            return parent;
        }

        inline const csl::ut::LinkList<GOCTransform>& GetChildren() {
            return children;
        }

        inline csl::math::Transform& GetTransform() {
            return transform;
        }

        inline fnd::HFrame& GetFrame() {
            return frame;
        }
        
        GOCOMPONENT_CLASS_DECLARATION(GOCTransform)
    };
}
