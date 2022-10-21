/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Device.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 17/10/2022 17:56:17													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_Device_CPP_
#define _Sqwack_Engine_Device_CPP_

#pragma once
#include "Device.h"
#include "Adapter.h"
 
namespace Sqwack
{

	Device::Device() :
		m_ID3DDevice(nullptr),
		m_RtvDescriptorSize(0),
		m_DsvDescriptorSize(0),
		m_CbvSrvDescriptorSize(0)
	{

	}

	Device::~Device()
	{

	}

	Device* Device::Create()
	{
		return new Device();
	}



	void Device::Init(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter4)
	{
		CreateDevice(adapter4);

	}



	bool Device::EnableDebugLayer()
	{
		Microsoft::WRL::ComPtr<ID3D12Debug>	debugController;

		DXCall(HRESULT hr_ = D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)), hr_);

		debugController->EnableDebugLayer();

		return SUCCEEDED(hr_);
	}

	bool Device::CheckFeatureSupport()
	{
		return false;
	}

	void Device::CreateDevice(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter4)
	{
#ifdef	SQWACK_DEBUG

		//Enable DX12 debug layer
		EnableDebugLayer();

#endif

		auto dxgiAdapter4{ adapter4 };

		DXCall(HRESULT hr_ = D3D12CreateDevice(dxgiAdapter4.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_ID3DDevice)), hr_);
	}


}









#endif // !_Sqwack_Engine_Device_CPP_

