#pragma once

namespace SurfRide {
    class Slice {
    public:
        SRS_SLICE* sliceData;
        uint64_t unk1;
        Vector2 fixedSize;
        uint32_t flags;
        short cropIndex0;

        Slice(SRS_SLICE* sliceData);
    };

    class SliceCast : public Cast3D {
    public:
        SRS_SLICECAST* sliceCastData;
        SRS_SLICE* slices;
        Vector2 size;
        bool bool100;

        SliceCast(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);

        static Vector2 CalcPivot(float width, float height, const SRS_SLICECAST& sliceCastData);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual Vector2 GetWorldSize() = 0;
        virtual Vector2 GetLocalSize() const = 0;
        virtual void SetLocalSize(const Vector2& size) = 0;
        virtual void SetSliceWidth(unsigned int index, float width) = 0;
        virtual void SetSliceHeight(unsigned int index, float height) = 0;
        virtual void SetPatternIndex(int index) = 0;
    };

    class SliceCast3D : public SliceCast {
    public:
        int unk301;
        void* unk302;
        SliceCast3D(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);
        virtual void MakeCellData(bool, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void Draw(DrawInterface* drawInterface, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual unsigned int GetCellCount() const override;
        virtual void InitializeCellFromLayerBuffer(void* layerBuffer, unsigned int index) override;
        virtual void CopyCellToLayerBuffer(void* data, void* layerBuffer, unsigned int index) override;
        virtual SRS_CELL3D* GetCell() const override;
        virtual Vector2 GetWorldSize() override;
        virtual Vector2 GetLocalSize() const override;
        virtual void SetLocalSize(const Vector2& size) override;
        virtual void SetSliceWidth(unsigned int index, float width) override;
        virtual void SetSliceHeight(unsigned int index, float height) override;
        virtual void SetPatternIndex(int index) override;
    };
}
