#pragma once

namespace SurfRide {
    class Text;
    class ImageCast : public Cast3D {
    public:

        SRS_IMAGECAST* imageCastData;
        Text* text;
        Vector2 size;
        short cropIndex[2];
        SrTexCoord cropRectMin[2];
        SrTexCoord cropRectMax[2];
        bool cropRectDirty[2];

        ImageCast(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);
        
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual Vector2 GetWorldSize() = 0;
        virtual Vector2 GetLocalSize() const = 0;
        virtual void SetLocalSize(const Vector2& size) = 0;
        virtual void SetPatternIndex(int index) = 0;
        virtual void SetCropIndex(ECropSurface surface, int index);
        virtual void InitializeText(SRS_TEXTDATA* textData) = 0;

        void SetText(const char* str);
        Vector2 GetLocalSize_() const;
        void SetLocalSize_(const Vector2& size);
        void SetPatternIndex_(int index);
        static Vector2 CalcPivot(float width, float height, const SRS_IMAGECAST& imageCastData);
    };

    class ImageCast3D : public ImageCast {
    public:
        int unk301;
        SRS_CELL3D* cell;
        ImageCast3D(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);
        virtual void MakeCellData(bool, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void UpdateThis(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) override;
        virtual unsigned int GetCellCount() const override;
        virtual void InitializeCellFromLayerBuffer(void* layerBuffer, unsigned int index) override;
        virtual void CopyCellToLayerBuffer(void* data, void* layerBuffer, unsigned int index) override;
        virtual SRS_CELL3D* GetCell() const override;
        virtual Vector2 GetWorldSize() override;
        virtual Vector2 GetLocalSize() const override;
        virtual void SetLocalSize(const Vector2& size) override;
        virtual void SetPatternIndex(int index) override;
        virtual void SetCropIndex(ECropSurface surface, int index) override;
        virtual void InitializeText(SRS_TEXTDATA* textData) override;
    };
}
