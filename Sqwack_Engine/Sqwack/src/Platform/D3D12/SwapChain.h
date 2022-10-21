/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: SwapChain.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 20/10/2022 14:40:15													 
//==============================================================================//

#ifndef _Sqwack_Engine_SwapChain_H_
#define _Sqwack_Engine_SwapChain_H_

#pragma once
#include "Fence.h"
#include "D3D12Headers.h"

namespace Sqwack 
{
	class SwapChain
	{
	public:

		
		SwapChain(const DXGI_SWAP_CHAIN_DESC& desc);
		~SwapChain();

		
		SwapChain() = delete;
		SwapChain& operator= (const SwapChain& swapChain) = delete;
		SwapChain(const SwapChain& swapchain) = delete;
		



		void Init(const DXGI_SWAP_CHAIN_DESC& desc, Microsoft::WRL::ComPtr<IDXGIFactory4> factory4);


	private:

		Microsoft::WRL::ComPtr<IDXGIFactory4>          m_Factory4;
		Fence                                          m_Fence;

		DXGI_SWAP_CHAIN_DESC                           m_SwapChainDesc;


	};
}
#endif // !_Sqwack_Engine_SwapChain_H_

