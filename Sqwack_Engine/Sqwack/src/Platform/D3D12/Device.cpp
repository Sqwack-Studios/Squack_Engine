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
		m_ID3DDevice(nullptr)
		//m_RtvDescriptorSize(0),
		//m_DsvDescriptorSize(0),
		//m_CbvSrvDescriptorSize(0)
	{

	}

	Device::~Device()
	{

	}

	std::unique_ptr<Device> Device::Create()
	{
		return std::make_unique<Device> ();
	}



	void Device::Init(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter4)
	{
		CreateDevice(adapter4);

	}



	bool Device::EnableDebugLayer()
	{
		

		DXCall(HRESULT hr_ = D3D12GetDebugInterface(IID_PPV_ARGS(&m_debugController)), hr_);

		m_debugController->EnableDebugLayer();

		return SUCCEEDED(hr_);
	}

	bool Device::CheckFeatureSupport()
	{
		return false;
	}

	void Device::CreateDevice(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter4)
	{


		//Enable DX12 debug layer
		EnableDebugLayer();



		auto dxgiAdapter4{ adapter4 };

		DXCall(HRESULT hr_ = D3D12CreateDevice(dxgiAdapter4.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_ID3DDevice)), hr_);
	}


}









#endif // !_Sqwack_Engine_Device_CPP_

