/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Context.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 15/10/2022 14:44:25													 
//==============================================================================//

#ifndef _Sqwack_Engine_D3D12Context_H_
#define _Sqwack_Engine_D3D12Context_H_

#pragma once
#include "Sqwack/Core/Core.h"
#include "D3D12Headers.h"
#include "D3D12LogAssertion.h"


class D3D12Context
{
public:

	D3D12Context();
	D3D12Context(const D3D12Context& context) = delete;
	D3D12Context& operator=(const D3D12Context& context) = delete;
	~D3D12Context();

	bool Init();

private: 

	void QueryAdapters();
	void QueryAdaptersDisplays(Microsoft::WRL::ComPtr<IDXGIAdapter> adapter);
	void QueryDisplaySpecs(Microsoft::WRL::ComPtr<IDXGIOutput> output, DXGI_OUTPUT_DESC desc, DXGI_FORMAT format);

	inline bool CreateFactory(Microsoft::WRL::ComPtr<IDXGIFactory4>* factory);
	bool CheckFeatureSupport();
	bool CreateDevice(Microsoft::WRL::ComPtr<ID3D12Device>* device);
	bool EnableDebugLayer();


private:

	Microsoft::WRL::ComPtr<IDXGIFactory4>				m_dxgiFactory4;

	Microsoft::WRL::ComPtr<ID3D12Device>				m_Device;
	Microsoft::WRL::ComPtr<ID3D12Fence>					m_Fence;

	UINT												m_RtvDescriptorSize;
	UINT												m_DsvDescriptorSize;
	UINT												m_CbvSrvDescriptorSize;

	


	//--------------------- ADAPTER & DISPLAY -----------------------//
	struct DisplayDescs
	{
		DXGI_OUTPUT_DESC								outputDesc{};
		std::vector<DXGI_MODE_DESC>						modeDesc{};
	};

	Microsoft::WRL::ComPtr<IDXGIAdapter>				m_dxgiAdapter;
	DXGI_ADAPTER_DESC									m_adapterDesc;

	DisplayDescs										m_outputsDescs;
	
	


private:



};
#endif // !_Sqwack_Engine_D3D12Context_H_

