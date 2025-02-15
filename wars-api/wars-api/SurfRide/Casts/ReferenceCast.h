#pragma once

namespace SurfRide
{
	class ReferenceCast : public Cast3D {
	public:
		SRS_REFERENCECAST* referenceCastData;
		Layer* refLayer;
		uint32_t animationId;
		float animationFrame;
		bool isFlag2Set;

		ReferenceCast(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateThis(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void Draw(DrawInterface* drawInterface, Transform* transformLayerBuffer, void* cellLayerBuffer) override {}
        virtual void InitializeTransformFromLayerBuffer(Transform* layerBuffer) override;
	};
}
