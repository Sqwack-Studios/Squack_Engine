/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Context.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 17/10/2022 17:56:17													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_D3D12Context_CPP_
#define _Sqwack_Engine_D3D12Context_CPP_

#pragma once
#include "D3D12Context.h"


D3D12Context::D3D12Context() :
	m_dxgiAdapter(nullptr),
	m_Device(nullptr),
	m_dxgiFactory4(nullptr),
	m_adapterDesc({})
{

}

D3D12Context::~D3D12Context()
{

}


bool D3D12Context::Init()
{
	if (!CreateFactory(&m_dxgiFactory4))
		return false;
	if (!CreateDevice(&m_Device))
		return false;

	
	return false;
}

bool D3D12Context::CreateFactory(Microsoft::WRL::ComPtr<IDXGIFactory4>* factory)
{
	DXCall(HRESULT hr_ = CreateDXGIFactory1(IID_PPV_ARGS(&m_dxgiFactory4)), hr_);

	
	return (hr_ >= 0) ? true : false;
}

bool D3D12Context::EnableDebugLayer()
{
	Microsoft::WRL::ComPtr<ID3D12Debug>	debugController;

	DXCall(HRESULT hr_ = D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)), hr_);

	debugController->EnableDebugLayer();

	return (hr_ >= 0) ? true : false;
}

bool D3D12Context::CheckFeatureSupport()
{
	return false;
}

bool D3D12Context::CreateDevice(Microsoft::WRL::ComPtr<ID3D12Device>* device)
{
#ifdef	SQWACK_DEBUG
	//Enable DX12 debug layer
	if (!EnableDebugLayer())
		return false;
#endif

	DXCall(HRESULT hr_ = D3D12CreateDevice(m_dxgiAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_Device)),hr_);

	HRESULT warpHr_;

	if (FAILED(hr_)) //Fallback to WARP adapters
	{
		Microsoft::WRL::ComPtr<IDXGIAdapter> pWarpAdapter;

		DXCall(warpHr_ = m_dxgiFactory4->EnumWarpAdapter(IID_PPV_ARGS(&pWarpAdapter)), warpHr_);
	}

	return (hr_ >= 0 || warpHr_ >= 0) ? true : false;
}



void D3D12Context::QueryAdapters()
{
	

	Microsoft::WRL::ComPtr<IDXGIAdapter> adapter{ nullptr };
	std::vector<Microsoft::WRL::ComPtr<IDXGIAdapter> > adaptersList;

	SIZE_T maxDedicatedVRAM{0};
	SIZE_T selectedAdapterIdx{ 0 };

	for (UINT adaptersCount{ 0 }; m_dxgiFactory4->EnumAdapters(adaptersCount, &adapter) != DXGI_ERROR_NOT_FOUND; ++adaptersCount)
	{
		DXGI_ADAPTER_DESC desc;
		adapter->GetDesc(&desc);


		std::cout << "[DirectX 12 LOG] "
			<< " **Adapter [" << adaptersCount << "] "
			<< " Name: " << desc.Description
			<< " VRAM: " << desc.DedicatedVideoMemory
			<< std::endl;


		if (desc.DedicatedVideoMemory > maxDedicatedVRAM)
		{
			selectedAdapterIdx = adaptersCount;
			maxDedicatedVRAM = desc.DedicatedVideoMemory;
			m_adapterDesc = desc;
		}

		adaptersList.push_back(adapter);
		
	}
	
	m_dxgiAdapter = adaptersList[selectedAdapterIdx].Get();
	
	//Also print displays
	QueryAdaptersDisplays(m_dxgiAdapter);

	
}

void D3D12Context::QueryAdaptersDisplays(Microsoft::WRL::ComPtr<IDXGIAdapter> adapter)
{

	Microsoft::WRL::ComPtr<IDXGIOutput> output;

	for (UINT i{ 0 }; adapter->EnumOutputs(i, &output) != DXGI_ERROR_NOT_FOUND; ++i)
	{
		DXGI_OUTPUT_DESC desc;
		output->GetDesc(&desc);
	
		QueryDisplaySpecs(output, desc, DXGI_FORMAT_B8G8R8A8_UNORM);

	}
}

void D3D12Context::QueryDisplaySpecs(Microsoft::WRL::ComPtr<IDXGIOutput> output, DXGI_OUTPUT_DESC outputDesc,  DXGI_FORMAT format)
{

	UINT modeCount{ 0 };
	UINT flags{ 0 };
	DisplayDescs displayDesc;
	

	//nullptr outputs mode count
	output->GetDisplayModeList(format, flags, &modeCount, nullptr);

	displayDesc.outputDesc = outputDesc;
	displayDesc.modeDesc = std::vector<DXGI_MODE_DESC>(modeCount);


	output->GetDisplayModeList(format, flags, &modeCount, &displayDesc.modeDesc[0]);

	std::cout << "[DirectX 12 Log] "
		<< " **Output: " << outputDesc.DeviceName << std::endl;

	for (const auto& mode : displayDesc.modeDesc)
	{
		std::cout << "Width: " << mode.Width
			<< " Height: " << mode.Height
			<< " Refresh: " << mode.RefreshRate.Numerator << "/" << mode.RefreshRate.Denominator
			<< std::endl;
	}

	
}








#endif // !_Sqwack_Engine_D3D12Context_CPP_

