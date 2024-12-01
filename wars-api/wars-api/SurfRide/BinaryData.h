#pragma once

namespace SurfRide
{
	//struct SRS_BINARY_FILE_HEADER_CHUNK {
	//	SRS_CHUNK_HEADER chunkHeader;
	//	SRS_BINARY_FILE_HEADER_CHUNK_HEADER header;

	//	struct ChunkInfo {
	//		SRS_PROJECT_CHUNK* projectChunk;
	//		SRS_TEXTURELIST_CHUNK* textureListChunk;

	//		unsigned int GetTextureListCount() const;
	//		TextureListIterator GetTextureListIteratorBegin() const;
	//		TextureListIterator GetTextureList(unsigned int) const;
	//		ProjectIterator GetProject() const;
	//	};

	//	static ChunkInfo GetChunkInfo(void* data);
	//};

	class BinaryData : public ReferencedObject {
		void* data{};
	public:
		BinaryData(void* data);
		void ResolveAddress();
		static void ResolveAddress(void* data);
		Project* ApplyMemoryImageToProject(bool unkParam);
		SRS_CHUNK_HEADER* GetBinaryFileHeader();
		void ResetAddress(void* start, void* end, unsigned int size);
	};

	Project* ApplyMemoryImageToProject(void* image, bool unkParam);
}
