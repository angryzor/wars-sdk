#pragma once

namespace hh::ut {
    namespace internal {
        class StateManagerImpl : public fnd::ReferencedObject {
        public:
            csl::ut::MoveArray<StateDescImpl*> stateDescs;

            StateManagerImpl(size_t size);
            virtual ~StateManagerImpl();
        };
    }

    class StateManager : public internal::StateManagerImpl {
    public:
        StateManager(size_t size);

        void AddStateDesc(int stateId, StateDesc* stateDesc);
        internal::StateDescImpl* GetStateDescImpl(int stateId) const;
    };
}
