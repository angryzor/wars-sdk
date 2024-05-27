#pragma once

namespace hh::fnd {
    class MessageQueue {
    public:
        class Entry : public ReferencedObject {
        public:
            enum class Flags {
                PENDING,
                IN_FLIGHT,
                HANDLED_FAILURE,
                HANDLED_SUCCESS,
            };
            fnd::Message* message;
            Flags flags;
        };

		csl::fnd::IAllocator* allocator;
		csl::ut::MoveArray<Entry*> messageBuffers[2];
    
        MessageQueue();
        void Reserve(csl::fnd::IAllocator* allocator, size_t size);
        Message* EnqueueMessage(const Message& message);
        void Dispatch(bool (*func)(const Message& message, void* userData), void* userData);
    };
}
