#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE 0x56454452444e4552ui64

namespace hh::needle {
    struct ShaderMaterialContainerCreationInfo {

    };

    struct BufferCreationInfo {
    };

    struct TextureCreationInfo {
    };
    
    struct TextureViewCreationInfo {
    };

    class ShaderMaterialContainer;
    class RenderingDevice : public TNeedleRefcountResource<NEEDLE_RESOURCE_RENDERING_DEVICE, NeedleRefcountResource> {
    public:
        virtual RenderingDeviceContext* CreateDeviceContext(unsigned int maybeId) = 0;
        virtual void* UnkFunc9() = 0;
        virtual void OtherCreateDeviceContext() = 0; // CreateDeviceDispatch?
        virtual Texture* CreateTexture(const TextureCreationInfo& creationInfo) = 0;
        virtual Texture* CreateTextureView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual RenderTarget* CreateRenderTarget(const TextureCreationInfo& creationInfo) = 0;
        virtual RenderTarget* CreateRenderTargetView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual DepthStencil* CreateDepthStencil(const TextureCreationInfo& creationInfo) = 0;
        virtual DepthStencil* CreateDepthStencilView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual DepthStencil* CreateUnorderedAccessView(const TextureViewCreationInfo& creationInfo, NeedleRefcountResource* resource) = 0;
        virtual Buffer* CreateVertexBuffer(const BufferCreationInfo& creationInfo) = 0;
        virtual Buffer* CreateIndexBuffer(const BufferCreationInfo& creationInfo) = 0;
        virtual bool CreateVertexLayout(const SInputElement* inputElement, uint32_t unkParam, VertexLayout** vertexLayout) = 0;
        virtual void UnkFunc20() = 0;
        virtual void UnkFunc21() = 0;
        virtual VertexShader* CreateVertexShader(const void* data, size_t size) = 0;
        virtual PixelShader* CreatePixelShader(const void* data, size_t size) = 0;
        virtual ComputeShader* CreateComputeShader(const void* data, size_t size) = 0;
        virtual void UnkFunc25() = 0;
        virtual void UnkFunc26() = 0;
        virtual void UnkFunc27() = 0;
        virtual void UnkFunc28() = 0;
        virtual bool CreateShaderMaterialContainer(const ShaderMaterialContainerCreationInfo& creationInfo, ShaderMaterialContainer** shaderMaterialContainer) = 0;
        virtual void UnkFunc30() = 0;
        virtual void UnkFunc31() = 0;
        virtual void UnkFunc32() = 0;
        virtual void UnkFunc33() = 0;
        virtual void UnkFunc34() = 0;
        virtual void UnkFunc35() = 0;
        virtual void UnkFunc36() = 0;
        virtual void UnkFunc37() = 0;
        virtual void UnkFunc38() = 0;
        virtual void UnkFunc39() = 0;
        virtual void UnkFunc40() = 0;
        virtual void UnkFunc41() = 0;
        virtual void UnkFunc42() = 0;
        virtual void UnkFunc43() = 0;
        virtual void UnkFunc44() = 0;
        virtual void UnkFunc45() = 0;
        virtual void UnkFunc46() = 0;
    };
}