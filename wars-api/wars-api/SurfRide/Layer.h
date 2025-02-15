#pragma once

namespace SurfRide
{
	class Cast;
	class ReferenceCast;
	class ImageCastCast;
	class SliceCast;
	class Scene;

	// class CastInstanceBuffer : public Base {
	// public:
	// 	union CastInstance {
	// 		Cast cast;
	// 		ImageCast imageCast;
	// 		ReferenceCast referenceCast;
	// 		SliceCast sliceCast;
	// 	};

	// 	csl::fnd::IAllocator* allocator;
	// 	CastInstance* buffer;

	// 	CastInstanceBuffer(csl::fnd::IAllocator* allocator);

	// 	CastInstance* GetCastInstance(unsigned int idx);
	// };

	class Project;
	class Layer : public ReferencedObject
	{
	public:
		enum class Flag : uint32_t {
			IS_3D,
		};

		SRS_LAYER* layerData;
		uint32_t unk1;
		const char* name;
		Scene* scene;
		ReferenceCast* referenceCast;
		Cast** casts;
		uint32_t castCount;
		Transform* transforms;
		uint32_t transformCount;
		CellList* cells;
		Cast* firstCast;
		Cast* lastCast;
		uint32_t currentAnimationIndex;
		float currentFrame;
		float currentFrame2;
		float startFrame;
		float endFrame;
		float unk11a;
		float currentFrame3;
		uint32_t repeatCount;
		csl::ut::Bitset<Flag> flags;
		uint16_t unk14;
		bool atAnimationStart;
		bool pause;
		bool repeat;
		bool dontSetRepeating;
		bool atAnimationEnd;
		bool playInReverse;
		bool unk16;
		Project* project;

		Layer(const SRS_LAYER& layerData, Scene* scene);

		//void SetHideFlag(bool in_hide)
		//{
		//	if (in_hide)
		//		flags |= 0x100;
		//	else
		//		flags &= ~0x100;
		//}

		const char* GetAnimationName() const;
		const char* GetAnimationName(unsigned int animationIdx) const;
		int GetAnimationIndex(const char* animationName) const;
		int GetAnimationID(const char* animationName) const;
		float GetAnimationLength(const char* animationName) const;
		bool ApplyAnimation(int animationId);
		bool ApplyAnimation(const char* animationName);
		bool ApplyAnimationByIndex(unsigned int animationIdx);
		void SetCurrentFrame(float frame);
		void SetHideFlag(bool enabled);
		void SetRepeatFlag(bool enabled);
		bool Is3D();

		Cast* GetCast(unsigned int id) const;
		Cast* GetCast(const char* name) const;

#ifndef EXPORTING_TYPES
		inline NullTerminatedCollection<Cast, &Cast::NextCast> GetCasts() const {
			return { firstCast };
		}
#endif

	private:
		Cast* CopyCastsRecursively(SRS_CASTNODE* casts, SRS_TRS3D* transforms, int idx, Cast* parentCast, unsigned int* totalTransforms);
		void InitializeAnimation();
		void SetUpAnimationLinks(SRS_ANIMATION* animation);
		void UpdateFrame(float timestep);
	};

	struct LayerCollection {
		SRS_LAYER* current;
		SRS_LAYER* end;
	};

	struct LayerIterator {
		SRS_LAYER* layer;
		
		void Next();
		CastCollection GetCasts() const;
	};
}