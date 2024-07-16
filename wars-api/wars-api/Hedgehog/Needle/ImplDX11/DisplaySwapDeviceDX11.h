#pragma once

namespace hh::needle::ImplDX11 {
    class DisplaySwapDeviceDX11 : public DisplaySwapDevice {
    public:
        IDXGISwapChain* swapChain;
        DisplaySwapDeviceDX11(ID3D11Device* d3dDevice);

        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override;
        virtual uint64_t UnkFunc8() override;
        virtual bool ResizeBuffers(unsigned int* width, unsigned int* height) override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual bool GetFullScreenState() override;
        virtual uint64_t UnkFunc14() override;
        virtual uint64_t UnkFunc15() override;
        virtual uint64_t UnkFunc16() override;
        virtual uint64_t UnkFunc17() override;
        virtual uint64_t UnkFunc18() override;
        virtual uint64_t UnkFunc19() override;
        virtual bool Present(unsigned int flags) override;
    };
}
