/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Adapter.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 18/10/2022 20:42:24													 
//==============================================================================//

#ifndef _Sqwack_Engine_Adapter_H_
#define _Sqwack_Engine_Adapter_H_

#pragma once
#include "D3D12Headers.h"
#include "D3D12LogAssertion.h"

namespace Sqwack
{


	struct DisplayDescs
	{
		DXGI_OUTPUT_DESC                                outputDesc{};
		std::vector<DXGI_MODE_DESC>                     modeDesc{};
	};

	class Adapter
	{
	public:



	public:
		Adapter(Microsoft::WRL::ComPtr<IDXGIAdapter4> adapter);
		Adapter(const Adapter& adapter) = delete;
		Adapter& operator= (const Adapter& adapter) = delete;
		~Adapter();


		void Init();

		static Microsoft::WRL::ComPtr<IDXGIAdapter4> QueryBestAdapter(Microsoft::WRL::ComPtr<IDXGIFactory4> factory4);
		static std::unique_ptr<Adapter> Create(Microsoft::WRL::ComPtr<IDXGIAdapter4>);

		inline Microsoft::WRL::ComPtr<IDXGIAdapter4> GetDXGIAdapter() const { return m_dxgiAdapter; }
		inline const std::vector<DisplayDescs>& GetAdapterDisplayDescs() { return m_outputsDescs; }


	private:
		//--------------------- ADAPTER & DISPLAY -----------------------//

		DisplayDescs QueryDisplaySpecs(Microsoft::WRL::ComPtr<IDXGIOutput> output, DXGI_OUTPUT_DESC outputDesc, DXGI_FORMAT format);
		void FillDisplayDescs();


		Microsoft::WRL::ComPtr<IDXGIAdapter4>				m_dxgiAdapter;
		DXGI_ADAPTER_DESC									m_adapterDesc;

		std::vector<DisplayDescs>                           m_outputsDescs;

	};

}
#endif // !_Sqwack_Engine_Adapter_H_

