/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Descriptor.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 21/10/2022 19:30:20													 
//==============================================================================//

#ifndef _Sqwack_Engine_Descriptor_H_
#define _Sqwack_Engine_Descriptor_H_

#pragma once
#include "D3D12Headers.h"



namespace Sqwack

{
	class Descriptor
	{

	public:

		Descriptor();
		~Descriptor();

		D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView(_UINT8 currentBackBuffer) const;


		static std::unique_ptr<Descriptor> Create();



		void Init(Microsoft::WRL::ComPtr<ID3D12Device> device);
		void CreateRTV(Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain, Microsoft::WRL::ComPtr<ID3D12Device> device);
		void CreateDSV(Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain, Microsoft::WRL::ComPtr<ID3D12Device> device, const D3D12_RESOURCE_DESC& desc);
		D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView() const;

		inline Microsoft::WRL::ComPtr<ID3D12Resource> GetDepthStencilBuffer() { return m_DepthStencilBuffer; }

	private:

		UINT												m_RtvDescriptorSize;
		UINT												m_DsvDescriptorSize;
		UINT												m_CbvSrvDescriptorSize;

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>        m_RtvHeap;
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>        m_DsvHeap;

		Microsoft::WRL::ComPtr<ID3D12Resource>              m_SwapChainBuffer[Window::BackBufferCount];
		Microsoft::WRL::ComPtr<ID3D12Resource>              m_DepthStencilBuffer;
	};
}
#endif // !_Sqwack_Engine_Descriptor_H_

