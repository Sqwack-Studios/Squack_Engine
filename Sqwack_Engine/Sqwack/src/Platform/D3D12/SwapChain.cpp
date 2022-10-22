/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: SwapChain.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 21/10/2022 12:30:25													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_SwapChain_CPP_
#define _Sqwack_Engine_SwapChain_CPP_


#pragma once
#include "SwapChain.h"
#include "D3D12LogAssertion.h"



namespace Sqwack
{

	SwapChain::SwapChain():
		m_CommandQueue(nullptr),
		m_SwapChain(nullptr),
		m_CurrentBackBuffer(0),
		m_SwapChainDesc(DXGI_SWAP_CHAIN_DESC{})
	{

	}

	void SwapChain::Init(Microsoft::WRL::ComPtr<IDXGIFactory4> factory4, Microsoft::WRL::ComPtr<ID3D12Device> device)
	{
		Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory4{ factory4 };
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };


		//Create and start the command queue
		m_CommandQueue = CommandQueue::Create();
		m_CommandQueue->Init(id3dDevice, Window::BackBufferCount);

		//Create descriptors
		m_Descriptor = Descriptor::Create();
		m_Descriptor->Init(id3dDevice);

		//Initialize the swap chain
		m_SwapChain.Reset();

	}

	SwapChain::~SwapChain()
	{

	}

	void SwapChain::CreateSwapChain(Microsoft::WRL::ComPtr<IDXGIFactory4> factory4, Microsoft::WRL::ComPtr<ID3D12Device> device, DXGI_SWAP_CHAIN_DESC& desc)
	{
		Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory4{ factory4 };
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };

		bool check{false};
		if (m_CommandQueue->GetID3DCommandQueue())
		{
			check = true;
		}

		DXCall(HRESULT hr_ = dxgiFactory4->CreateSwapChain(m_CommandQueue->GetID3DCommandQueue().Get(), &desc, m_SwapChain.GetAddressOf()), hr_);

		//Create the resources needed for the swap chain. After the resources are created, we might load them through the Renderer API?

		
		


		m_Descriptor->CreateRTV(m_SwapChain, id3dDevice);

		D3D12_RESOURCE_DESC dsvDesc;
		dsvDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
		dsvDesc.Alignment = 0;
		dsvDesc.Width = desc.BufferDesc.Width;
		dsvDesc.Height = desc.BufferDesc.Height;
		dsvDesc.DepthOrArraySize = 1;
		dsvDesc.MipLevels = 1;
		dsvDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		dsvDesc.SampleDesc.Count = 1; //TODO: MSAA support
		dsvDesc.SampleDesc.Quality = 0;
		dsvDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
		dsvDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

		m_Descriptor->CreateDSV(m_SwapChain, id3dDevice, dsvDesc);


		m_CommandQueue->GetCommandList(GetCurrentBackBuffer())->TransitionResource(m_Descriptor->GetDepthStencilBuffer(), D3D12_RESOURCE_STATE_COMMON, D3D12_RESOURCE_STATE_DEPTH_WRITE);
		
		for (size_t i = 0; i < Window::BackBufferCount; i++)
		{
			m_CommandQueue->GetCommandList(i)->Close();
		}

	}
}





#endif // !_Sqwack_Engine_SwapChain_CPP_

