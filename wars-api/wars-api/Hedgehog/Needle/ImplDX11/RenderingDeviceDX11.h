#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE_DX11 0x5F5F313156454452ui64

namespace hh::needle::ImplDX11 {
    // hh::needle::ImplDX11::CreateRenderingDeviceDX11(hh::needle::intrusive_ptr<hh::needle::RenderingDevice, hh::needle::SRefCountAddReleaseNeedleObject, true> *, hh::needle::intrusive_ptr<hh::needle::RenderingDeviceContext, hh::needle::SRefCountAddReleaseNeedleObject, true> *, const hh::needle::DeviceCreationSetting *, hh::needle::intrusive_ptr<hh::needle::DisplaySwapDevice, hh::needle::SRefCountAddReleaseNeedleObject, true> *, unsigned int)

    class RenderingDeviceDX11 : public RenderingDevice {
    public:
        static constexpr size_t resourceId = NEEDLE_RESOURCE_RENDERING_DEVICE_DX11;

        void* unk;
        DeviceObjectDX11* deviceObject;
        void* unk2; // see 0x155DFD450

        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
        virtual RenderingDeviceContextDX11* CreateDeviceContext(unsigned int maybeId) override;
        virtual void* UnkFunc9() override;
        virtual void OtherCreateDeviceContext() override; // CreateDeviceDispatch?
        virtual Texture* CreateTexture(const TextureCreationInfo& creationInfo) override;
        virtual Texture* CreateTextureView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) override;
        virtual RenderTarget* CreateRenderTarget(const TextureCreationInfo& creationInfo) override;
        virtual RenderTarget* CreateRenderTargetView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) override;
        virtual DepthStencil* CreateDepthStencil(const TextureCreationInfo& creationInfo) override;
        virtual DepthStencil* CreateDepthStencilView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) override;
        virtual DepthStencil* CreateUnorderedAccessView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) override;
        virtual Buffer* CreateVertexBuffer(const BufferCreationInfo& creationInfo) override;
        virtual Buffer* CreateIndexBuffer(const BufferCreationInfo& creationInfo) override;
        virtual bool CreateVertexLayout(const SInputElement* inputElement, uint32_t unkParam, VertexLayout** vertexLayout) override;
        virtual void UnkFunc20() override {}
        virtual void UnkFunc21() override;
        virtual VertexShader* CreateVertexShader(const void* data, size_t size) override;
        virtual PixelShader* CreatePixelShader(const void* data, size_t size) override;
        virtual ComputeShader* CreateComputeShader(const void* data, size_t size) override;
        virtual void UnkFunc25() override;
        virtual void UnkFunc26() override;
        virtual void UnkFunc27() override;
        virtual void UnkFunc28() override;
        virtual bool CreateShaderMaterialContainer(const ShaderMaterialContainerCreationInfo& creationInfo, ShaderMaterialContainer** shaderMaterialContainer) override;
        virtual void UnkFunc30() override;
        virtual void UnkFunc31() override;
        virtual void UnkFunc32() override;
        virtual void UnkFunc33() override;
        virtual void UnkFunc34() override;
        virtual void UnkFunc35() override;
        virtual void UnkFunc36() override {}
        virtual void UnkFunc37() override {}
        virtual void UnkFunc38() override;
        virtual void UnkFunc39() override;
        virtual void UnkFunc40() override;
        virtual void UnkFunc41() override;
        virtual void UnkFunc42() override;
        virtual void UnkFunc43() override;
        virtual void UnkFunc44() override;
        virtual void UnkFunc45() override;
        virtual void UnkFunc46() override;

        ID3D11Device* GetNativeDevice() const;
    };
}
