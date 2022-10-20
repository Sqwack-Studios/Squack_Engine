/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Context.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 20/10/2022 17:50:03													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_D3D12Context_CPP_
#define _Sqwack_Engine_D3D12Context_CPP_

#pragma once
#include "D3D12Context.h"
#include "D3D12LogAssertion.h"

namespace Sqwack
{
	D3D12Context::D3D12Context() :
		m_dxgiFactory4(nullptr),
		m_Device(nullptr),
		m_Adapter(nullptr)
	{

	}

	D3D12Context::~D3D12Context()
	{

	}

	D3D12Context* D3D12Context::Create()
	{
		return new D3D12Context();
	}

	void D3D12Context::Init()
	{
		CreateFactory();

		//Query the best adapter (VRAM based selection) and use it to construct the Adapter Class
		Microsoft::WRL::ComPtr<IDXGIAdapter4> dxgiAdapter4 = Adapter::QueryBestAdapter(m_dxgiFactory4);
		m_Adapter = std::unique_ptr<Adapter>(Adapter::Create(dxgiAdapter4));
		m_Adapter->Init();

		//Use the adapter to build the D3D12 Device
		m_Device = std::unique_ptr<Device>(Device::Create());
		m_Device->Init(m_Adapter->GetDXGIAdapter());


	}

	void D3D12Context::CreateFactory()
	{
		DXCall(HRESULT hr_ = CreateDXGIFactory1(IID_PPV_ARGS(&m_dxgiFactory4)), hr_);
	}
}





#endif // !_Sqwack_Engine_D3D12Context_CPP_

