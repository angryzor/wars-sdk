#pragma once

namespace hh::game {
	struct WorldObjectCInfo {
		csl::ut::InplaceMoveArray<hh::game::GOComponentConfiguration, 5> componentConfig;
		uint64_t unk1; // see 1.40 0x140D48348 -- Packfile*??? see 0x140CFC8C5
                       //     1.41 0x140D4B1F7
	};

    class ObjectWorldChunk;
    class ObjectWorldChunkListener {
    public:
        virtual ~ObjectWorldChunkListener() = default;
        virtual void ObjectDataAddedCallback(const ObjectWorldChunk* chunk, const ObjectData* objectData) {}
        virtual void ObjectDataRemovedCallback(const ObjectWorldChunk* chunk, const ObjectData* objectData) {}
        virtual void ObjectDataChangedCallback(const ObjectWorldChunk* chunk, const ObjectData* objectData) {}
        virtual void FinishEditorCallback() {}
        virtual void OWC_UnkFunc1() {}
    };

	// If spawntype is ETERNAL or EXTRINSIC, then don't spawn, otherwise spawn.
	bool IsSpawnBySpawnType(const GameObjectClass* gameObjectClass);

    bool GetStatusEternal(const GameObjectClass* gameObjectClass, int* type);
    bool GetStatusExtrinsic(const GameObjectClass* gameObjectClass, int* type);

    class ObjectWorldChunkLayer;
    class ObjectWorldChunk : public fnd::ReferencedObject, public GameManagerListener {
        enum class Flag : uint8_t {
            EDITOR,
        };

        typedef bool (*ObjectAttribute)(const GameObjectClass* gameObjectClass, int* attributeFlags);

        GameManager* gameManager;
        csl::ut::Bitset<Flag> flags;
        csl::ut::MoveArray<ObjectWorldChunkListener*> listeners;
        csl::ut::MoveArray<ObjectWorldChunkLayer*> layers;
        csl::ut::StringMap<ObjectWorldChunkLayer*> layersByName;
        csl::ut::MoveArray<GameObject*> objects;
        csl::ut::MoveArray<WorldObjectStatus> objectStatuses;
        csl::ut::StringMap<WorldObjectStatus*> objectStatusesByName;
        csl::ut::PointerMap<ObjectData*, int> objectIndicesByObjectData;
        csl::ut::PointerMap<GameObjectClass*, csl::ut::MoveArray<GameObject*>*> objectsByClass;
        csl::ut::MoveArray<void*> unk11;
    public:
        CREATE_FUNC(ObjectWorldChunk, GameManager* gameManager);
		virtual void GameObjectRemovedCallback(GameManager* gameManager, GameObject* gameObject);
        void AddLayer(ObjectWorldChunkLayer* layer);
        inline void RemoveLayer(ObjectWorldChunkLayer* layer);
        void RemoveLayerAll();
        const csl::ut::MoveArray<ObjectWorldChunkLayer*>& GetLayers() const;
        void SetLayerEnabled(const char* name, bool enabled);

        ObjectWorldChunkLayer* GetLayerByName(const char* name) const;

        void AddWorldObjectStatus(ObjectData* objectData, bool enabled);
        void RemoveWorldObjectStatus(ObjectData* objectData);

        void AddListener(ObjectWorldChunkListener* listener);
        void RemoveListener(ObjectWorldChunkListener* listener);
        void Despawn(const ObjectData* objectData); // inlined :/
        void DespawnByIndex(int index);
        ObjectDataAccessor GetObjectDataByObjectId(ObjectId id) const;
        ObjectDataAccessor GetObjectDataByName(const char* name) const;
        GameObject* Spawn(const ObjectData* objectData);
        GameObject* SpawnByObjectId(ObjectId id);
        GameObject* SpawnByObjectId(ObjectId id, ObjectAttribute filter);
        GameObject* SpawnByIndex(int index, ObjectAttribute filter);
        void SpawnByAttribute(ObjectAttribute filter);

        GameObject* GetGameObject(const ObjectData* objectData) const;
        GameObject* GetGameObjectByObjectId(ObjectId id) const;
        WorldObjectStatus GetWorldObjectStatusByObjectId(ObjectId id) const;

        inline const csl::ut::MoveArray<WorldObjectStatus>& GetObjectStatuses() const {
            return objectStatuses;
        }

        inline int GetObjectIndexByObjectData(ObjectData* objData) const {
            return objectIndicesByObjectData.GetValueOrFallback(objData, -1);
        }

        inline int GetObjectIndexById(ObjectId id) const {
            auto* objData = GetWorldObjectStatusByObjectId(id).objectData;
            return objData == nullptr ? -1 : GetObjectIndexByObjectData(objData);
        }

        inline GameObject* GetObjectByIndex(int i) const {
            return objects[i];
        }

        inline WorldObjectStatus GetWorldObjectStatusByIndex(int i) const {
            return objectStatuses[i];
        }

        inline void DespawnAll() {
            for (int i = 0; i < objects.size(); i++) {
                DespawnByIndex(i);
            }
        }
        
        void Restart(bool force);

        inline void ShutdownPendingObjects() {
            gameManager->ShutdownPendingObjects();
        }

        inline void SetEditorStatus(bool status);
        inline bool IsStatusEditor() {
            return flags.test(Flag::EDITOR);
        }
    };
}
