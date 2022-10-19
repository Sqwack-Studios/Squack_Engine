/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Device.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 15/10/2022 14:44:25													 
//==============================================================================//

#ifndef _Sqwack_Engine_Device_H_
#define _Sqwack_Engine_Device_H_

#pragma once
#include "Sqwack/Core/Core.h"
#include "D3D12Headers.h"
#include "D3D12LogAssertion.h"

class Adapter;

class Device
{
public:

	Device();
	Device(const Device& device) = delete;
	Device& operator=(const Device& device) = delete;
	~Device();

	bool Init();

public:

	inline const Microsoft::WRL::ComPtr<IDXGIFactory4>& GetFactory4() const { return m_dxgiFactory4; }

private: 

	inline bool CreateFactory();
	bool CheckFeatureSupport();
	bool CreateDevice();
	bool EnableDebugLayer();


private:

	Microsoft::WRL::ComPtr<IDXGIFactory4>				m_dxgiFactory4;

	Microsoft::WRL::ComPtr<ID3D12Device>				m_ID3DDevice;
	Microsoft::WRL::ComPtr<ID3D12Fence>					m_ID3DFence;

	UINT												m_RtvDescriptorSize;
	UINT												m_DsvDescriptorSize;
	UINT												m_CbvSrvDescriptorSize;

	std::shared_ptr<Adapter>                            m_Adapter;

	



	
	


private:



};
#endif // !_Sqwack_Engine_Device_H_

