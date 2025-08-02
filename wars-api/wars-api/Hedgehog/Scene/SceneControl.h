#pragma once
#include <ucsl/resources/scene/v106.h>

namespace hh::scene{
    class SceneManager;

    class SceneControl : public hh::fnd::ReferencedObject, public hh::game::GameManagerListener, public SceneNodeBuilder{
    public:
        struct Resource{
            SceneNode* node;
            int resourceType;
            SceneAnimation* animation;
        };

        struct CameraParameters{
            csl::math::Vector3 position;
            csl::math::Vector3 unk1;
            csl::math::Vector4 unk2;
            float twist;
            float fov;
            float aspectRatio;
            float nearClip;
            float farClip;
            bool isTarget;

            CameraParameters();
        };

        struct ControlNode{
            enum class ValueType : unsigned int{
                NONE,
                BOOLEAN,
                FLOAT,
                DOUBLE,
                INTEGER,
                STRING,
                VECTOR3,
                UNK
            };

            union Value{
                bool b;
                float f;
                double d;
                int i;
                const char* s;
            };

            const char* nodeName0;
            const char* parameterName;
            ValueType finalType;
            Value finalValue;
            const char* nodeName1;
            ValueType type;
            Value value;
            const char* nodeName2;
            bool hasCurveData;
            int unk0;
        };

        struct UnkStr1{
            int64_t unk0;
            short unk1;
            short unk2;
            int unk3;
            float unk4;
            int unk5;
        };

        struct TimelineNode{
            ucsl::resources::scene::v106::TimelineNode* nodeInfo;
            UnkStr1* unk0;
            SceneAnimation* animation;
            int64_t unk1;
        };

        struct PlayInfo{
            SceneControl* sceneControl;
            float currentSecond;
            float frameLength;
            float lengthInSeconds;
            float timeOffset;
            float unk1; //end?
            float fps;
            bool isCameraChange;
            char unk2;
            csl::fnd::IAllocator* allocator;
            csl::ut::MoveArray<TimelineNode> timelineNodes;
            csl::ut::MoveArray<UnkStr1> unk4;
            CameraParameters* currentCamParams0;
            CameraParameters* currentCamParams1;
            csl::math::Transform transform0;
            csl::math::Transform transform1;
            csl::ut::MoveArray<ControlNode>* controlNodes;
            csl::ut::MoveArray<SceneAnimation*> animations;

            PlayInfo(SceneControl* sceneControl, csl::fnd::IAllocator* allocator);
        };

        struct Camera{
            const char* filename;
            const char* cameraName;
            float start;
            float end;
        };

        SceneManager* sceneMgr;
        csl::ut::MoveArray<hh::game::GOComponent*> gocScenes;
        csl::ut::VariableString sceneName;
        int unk0;
        float unk1;
        csl::ut::MoveArray<ObjectInfoImpl> objects;
        csl::ut::MoveArray<Resource> resources;
        CameraParameters camParams;
        CameraParameters* currentCamParams;
        CameraParameters defaultCamParams;
        int64_t unk6;
        int64_t unk7;
        csl::math::Transform unk8;
        ResScene* resource;
        int64_t unk9;
        SceneBuilder::ResourceNameResolver* resourceNameResolver;
        hh::fnd::Packfile* scenePac;
        csl::ut::MoveArray<ControlNode> controlNodes;
        csl::ut::MoveArray<int64_t> unk10;
        short unk11;
        char unk13;
        char unk14;
        csl::ut::MoveArray<int64_t> unk15;
        SceneNodeBuilder* nodeBuilder;
        csl::ut::StringMap<int64_t> unk16;
        csl::ut::StringMap<int64_t> unk17;
        csl::ut::StringMap<int> resourceEnumByName;
        SceneBuilder::ResourceNameResolver resourceNameResolvers[11];
        PlayInfo playInfo;
        csl::ut::MoveArray<Camera> cameras;
        bool unk19;
        int unk20;
        short unk21;
        int unk22;
        float deltaTime;
        int unk23;

		virtual void GameObjectAddedCallback(hh::game::GameManager* gameManager, hh::game::GameObject* gameObject) override;

        virtual int64_t SNB_UnkFunc0(int64_t a2) override;
        virtual int64_t SNB_UnkFunc1(int64_t a2, int64_t a3) override;
        virtual int64_t SNB_UnkFunc2(int64_t a2) override;
        virtual int64_t SNB_UnkFunc3(int64_t a2) override;
        virtual int64_t SNB_UnkFunc4(int64_t a2, int a3, int a4) override;
        virtual int64_t SNB_UnkFunc5(int64_t a2, int64_t a3) override;
        virtual int64_t SNB_UnkFunc6(int64_t a2, int a3) override;

        SceneControl(csl::fnd::IAllocator* allocator, const char* sceneName);

        Camera* GetCamera(unsigned int idx);
    };
}
