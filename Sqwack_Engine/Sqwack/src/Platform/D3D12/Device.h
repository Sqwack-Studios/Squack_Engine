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
#include "Adapter.h"

namespace Sqwack
{
	class Device
	{
	public:

		Device();
		Device(const Device& device) = delete;
		Device& operator=(const Device& device) = delete;
		~Device();

		static std::unique_ptr<Device> Create();



		void Init(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter4);

	public:
		inline Microsoft::WRL::ComPtr<ID3D12Device> GetDevice() const { return m_ID3DDevice; }

	private:


		bool CheckFeatureSupport();
		void CreateDevice(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter4);
		bool EnableDebugLayer();


	private:


		Microsoft::WRL::ComPtr<ID3D12Device>				m_ID3DDevice;
		Microsoft::WRL::ComPtr<ID3D12Debug>	                m_debugController;








	private:



	};

}
#endif // !_Sqwack_Engine_Device_H_

