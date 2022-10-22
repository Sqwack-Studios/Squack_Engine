/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Context.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 20/10/2022 17:44:15													 
//==============================================================================//

#ifndef _Sqwack_Engine_D3D12Context_H_
#define _Sqwack_Engine_D3D12Context_H_

#pragma once
#include "Device.h"
#include "Adapter.h"

namespace Sqwack
{
	class D3D12Context
	{
	public:

		D3D12Context();
		~D3D12Context();

		inline Microsoft::WRL::ComPtr<IDXGIFactory4> GetFactory4() const { return m_dxgiFactory4; }



		void Init();
		

		static std::unique_ptr<D3D12Context> Create();

		inline Microsoft::WRL::ComPtr<ID3D12Device> GetDevice() const { return m_Device->GetDevice(); }

	private:

		void CreateFactory();

	private:

		std::unique_ptr<Device>                        m_Device;
		std::unique_ptr<Adapter>                       m_Adapter;

		Microsoft::WRL::ComPtr<IDXGIFactory4>          m_dxgiFactory4;
	
	};
}
#endif // !_Sqwack_Engine_D3D12Context_H_

