#pragma once

namespace SurfRide
{
	class Project;
	class Scene : public ReferencedObject
	{
		void LoadCamera();
		void LoadLayers();
	public:
		SRS_SCENE* sceneData;
		uint32_t unk1;
		Camera camera;
		unsigned int currentCameraIndex;
		Project* project;
		Layer** layers;
		uint32_t layerCount;
		uint32_t unk2;
		uint32_t flags;
		uint8_t unk3;
		uint8_t unk4;
		Project* project2;

		Scene(const SRS_SCENE& sceneData, Project* project);

		Layer* GetLayer(const char* layers);

#ifndef EXPORTING_TYPES
        inline CountedCollection<Layer*> GetLayers() const {
            return { layers, layerCount };
        }
#endif
	};

	struct SceneCollection {
		SRS_SCENE* current;
		SRS_SCENE* end;
	};

	struct SceneIterator {
		SRS_SCENE* scene;

		void Next();
		LayerCollection GetLayers() const;
	};
}
