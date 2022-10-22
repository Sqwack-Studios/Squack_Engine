/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Descriptor.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 21/10/2022 19:34:58													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_Descriptor_CPP_
#define _Sqwack_Engine_Descriptor_CPP_

#pragma once
#include "Descriptor.h"
#include "D3D12LogAssertion.h"

namespace Sqwack
{

	Descriptor::Descriptor():
		m_CbvSrvDescriptorSize(0),
		m_DsvDescriptorSize(0),
		m_RtvDescriptorSize(0)
	{

	}

	Descriptor::~Descriptor()
	{

	}


	std::unique_ptr<Descriptor> Descriptor::Create()
	{
		return std::make_unique<Descriptor>();
	}

	void Descriptor::Init(Microsoft::WRL::ComPtr<ID3D12Device> device)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };

		m_RtvDescriptorSize = id3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
		m_DsvDescriptorSize = id3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
		m_CbvSrvDescriptorSize = id3dDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

		D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc;
		rtvHeapDesc.NumDescriptors = Window::BackBufferCount;
		rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		rtvHeapDesc.NodeMask = 0;

		DXCall(HRESULT hRTV = id3dDevice->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(m_RtvHeap.GetAddressOf())), hRTV);

		D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc;
		dsvHeapDesc.NumDescriptors = 1;
		dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
		dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		dsvHeapDesc.NodeMask = 0;

		DXCall(HRESULT hDSV = id3dDevice->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(m_DsvHeap.GetAddressOf())), hDSV);


		
	}


	D3D12_CPU_DESCRIPTOR_HANDLE Descriptor::CurrentBackBufferView(_UINT8 currentBackBuffer) const
	{
		
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_RtvHeap->GetCPUDescriptorHandleForHeapStart(), static_cast<INT>(currentBackBuffer), m_RtvDescriptorSize);

		return rtvHandle;
	}

	D3D12_CPU_DESCRIPTOR_HANDLE Descriptor::DepthStencilView() const
	{
		return m_DsvHeap->GetCPUDescriptorHandleForHeapStart();
	}

	void Descriptor::CreateRTV(Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain, Microsoft::WRL::ComPtr<ID3D12Device> device)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };
		Microsoft::WRL::ComPtr<IDXGISwapChain> idxgiSwapChain{ swapChain };

		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHeapHandle(m_RtvHeap->GetCPUDescriptorHandleForHeapStart());

		for (UINT i = 0; i < Window::BackBufferCount; i++)
		{
			// i-th buffer in the swap chain 
			DXCall(HRESULT hr_ = swapChain->GetBuffer(i, IID_PPV_ARGS(&m_SwapChainBuffer[i])), hr_);

			//point an RTV to it
			id3dDevice->CreateRenderTargetView(m_SwapChainBuffer[i].Get(), nullptr, rtvHeapHandle);

			//offset the handler by the size of the descriptor
			rtvHeapHandle.Offset(1, m_RtvDescriptorSize);

		}



	}

	void Descriptor::CreateDSV(Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain, Microsoft::WRL::ComPtr<ID3D12Device> device, const D3D12_RESOURCE_DESC& resDesc)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };
		Microsoft::WRL::ComPtr<IDXGISwapChain> idxgiSwapChain{ swapChain };


		//Create the depth/stencil buffer view
		D3D12_CLEAR_VALUE optClear;

		optClear.Format = resDesc.Format;
		optClear.DepthStencil.Depth = 1.0f;
		optClear.DepthStencil.Stencil = 0;

		DXCall(HRESULT hr_ = id3dDevice->CreateCommittedResource(

			&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT),
			D3D12_HEAP_FLAG_NONE,
			&resDesc,
			D3D12_RESOURCE_STATE_COMMON,
			&optClear,
			IID_PPV_ARGS(m_DepthStencilBuffer.GetAddressOf())), hr_);

		//Create descriptor to mip level 0 of entire resource using the format of the resource
		id3dDevice->CreateDepthStencilView(m_DepthStencilBuffer.Get(), nullptr, DepthStencilView());
		
	}


}





#endif // !_Sqwack_Engine_Descriptor_CPP_

