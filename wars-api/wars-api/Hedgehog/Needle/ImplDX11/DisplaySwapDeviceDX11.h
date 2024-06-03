#pragma once

namespace hh::needle::ImplDX11 {
    class DisplaySwapDeviceDX11 : public DisplaySwapDevice {
    public:
        CREATE_FUNC(DisplaySwapDeviceDX11, ID3D11Device* d3dDevice);
    };
}
