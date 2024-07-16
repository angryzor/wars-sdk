#pragma once

namespace hh::needle {
    class DisplaySwapDevice : public NeedleRefcountObject {
    public:
        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual uint64_t UnkFunc8() = 0;
        virtual bool ResizeBuffers(unsigned int* width, unsigned int* height) = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual bool GetFullScreenState() = 0;
        virtual uint64_t UnkFunc14() = 0;
        virtual uint64_t UnkFunc15() = 0;
        virtual uint64_t UnkFunc16() = 0;
        virtual uint64_t UnkFunc17() = 0;
        virtual uint64_t UnkFunc18() = 0;
        virtual uint64_t UnkFunc19() = 0;
        virtual bool Present(unsigned int flags) = 0;
    };
}
