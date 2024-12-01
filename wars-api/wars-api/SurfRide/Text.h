#pragma once

namespace SurfRide {
    class ImageCast;
    class Text : public Base {
    public:
        SRS_TEXTDATA* textData;
        ImageCast* imageCast;
        Vector2 textAreaSize;
        uint32_t lineCount;
        uint32_t glyphCount;
        Vector2 startPosition;
        bool counted;
        const char* buffer; // UTF-8 encoded
        uint32_t bufferSize;

        Text(SRS_TEXTDATA* textData, ImageCast* imageCast);

        void SetText(const char* str);
        void Count();
        void AllocateTextCells();
    };

    class Text3D : Text {
    public:
        CellList* cells;
        Text3D(SRS_TEXTDATA* textData, ImageCast* imageCast);
    };
}
