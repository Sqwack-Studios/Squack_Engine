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


Device::Device() :
	m_ID3DDevice(nullptr),
	m_dxgiFactory4(nullptr),
	m_RtvDescriptorSize(0),
	m_DsvDescriptorSize(0),
	m_CbvSrvDescriptorSize(0)
{

}

Device::~Device()
{

}


bool Device::Init()
{
	if (!CreateFactory())
		return false;

	m_Adapter = Adapter::CreateAdapter(m_dxgiFactory4);
	if (!m_Adapter)
		return false;

	if (!CreateDevice())
		return false;

	
	return true;
}

bool Device::CreateFactory()
{
	DXCall(HRESULT hr_ = CreateDXGIFactory1(IID_PPV_ARGS(&m_dxgiFactory4)), hr_);

	
	return SUCCEEDED(hr_);
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

bool Device::CreateDevice()
{
#ifdef	SQWACK_DEBUG
	//Enable DX12 debug layer
	if (!EnableDebugLayer())
		return false;
#endif

	auto dxgiAdapter4{m_Adapter->GetDXGIAdapter()};

	DXCall(HRESULT hr_ = D3D12CreateDevice(dxgiAdapter4.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_ID3DDevice)), hr_);

	return SUCCEEDED(hr_);
}












#endif // !_Sqwack_Engine_Device_CPP_

