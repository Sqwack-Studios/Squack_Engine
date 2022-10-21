/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Adapter.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 18/10/2022 21:08:59													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_Adapter_CPP_
#define _Sqwack_Engine_Adapter_CPP_

#pragma once
#include "Adapter.h"

namespace Sqwack
{


	Adapter::Adapter(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter) :
		m_dxgiAdapter(adapter),
		m_adapterDesc(DXGI_ADAPTER_DESC{})
	{

	}

	Adapter::~Adapter()
	{

	}

	Microsoft::WRL::ComPtr<IDXGIAdapter4> Adapter::QueryBestAdapter(Microsoft::WRL::ComPtr<IDXGIFactory4> factory4)
	{
		Microsoft::WRL::ComPtr<IDXGIAdapter> dxgiAdapter{ nullptr };
		Microsoft::WRL::ComPtr<IDXGIAdapter4> dxgiAdapter4{ nullptr };
		Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory4{ factory4 };


		//Pick the best adapter (MOST AMOUNT OF VRAM)
		std::vector<Microsoft::WRL::ComPtr<IDXGIAdapter> > adaptersList;

		SIZE_T maxDedicatedVRAM{ 0 };
		SIZE_T selectedAdapterIdx{ 0 };

		for (UINT adaptersCount{ 0 }; dxgiFactory4->EnumAdapters(adaptersCount, &dxgiAdapter) != DXGI_ERROR_NOT_FOUND; ++adaptersCount)
		{
			DXGI_ADAPTER_DESC desc;
			dxgiAdapter->GetDesc(&desc);


			std::wcout << "[DirectX 12 LOG] "
				<< " **Adapter [" << adaptersCount << "] "
				<< " Name: " << desc.Description
				<< " VRAM: " << static_cast<float>(desc.DedicatedVideoMemory / std::pow(1024,3)) << " GB "
				<< std::endl;


			if (desc.DedicatedVideoMemory > maxDedicatedVRAM)
			{
				selectedAdapterIdx = adaptersCount;
				maxDedicatedVRAM = desc.DedicatedVideoMemory;
			}

			adaptersList.push_back(dxgiAdapter);

		}

		dxgiAdapter = adaptersList[selectedAdapterIdx].Get();

		DXCall(HRESULT hr_ = dxgiAdapter.As(&dxgiAdapter4), hr_);

		if (SUCCEEDED(hr_))
			return dxgiAdapter4;

		return nullptr;
	}

	Adapter* Adapter::Create(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter)
	{
		return new Adapter(adapter);
	}

	void Adapter::Init()
	{
		m_dxgiAdapter->GetDesc(&m_adapterDesc);
		FillDisplayDescs();
	}

	DisplayDescs Adapter::QueryDisplaySpecs(Microsoft::WRL::ComPtr<IDXGIOutput> output, DXGI_OUTPUT_DESC outputDesc, DXGI_FORMAT format)
	{

		UINT modeCount{ 0 };
		UINT flags{ 0 };
		DisplayDescs displayDesc;


		//nullptr outputs mode count
		output->GetDisplayModeList(format, flags, &modeCount, nullptr);

		displayDesc.outputDesc = outputDesc;
		displayDesc.modeDesc = std::vector<DXGI_MODE_DESC>(modeCount);


		output->GetDisplayModeList(format, flags, &modeCount, &displayDesc.modeDesc[0]);

		std::wcout << "[DirectX 12 Log] "
			<< " **Output: " << outputDesc.DeviceName << std::endl;

		for (const auto& mode : displayDesc.modeDesc)
		{
			std::wcout << "Width: " << mode.Width
				<< " Height: " << mode.Height
				<< " Refresh: " << mode.RefreshRate.Numerator << "/" << mode.RefreshRate.Denominator
				<< std::endl;
		}

		return displayDesc;

	}

	void Adapter::FillDisplayDescs()
	{
		Microsoft::WRL::ComPtr<IDXGIOutput> output;


		for (UINT i{ 0 }; m_dxgiAdapter->EnumOutputs(i, &output) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_OUTPUT_DESC desc;
			output->GetDesc(&desc);

			DisplayDescs displayDescs;
			displayDescs = QueryDisplaySpecs(output, desc, DXGI_FORMAT_B8G8R8A8_UNORM);
			m_outputsDescs.push_back(displayDescs);
		}

	}

}

#endif // !_Sqwack_Engine_Adapter_CPP_

