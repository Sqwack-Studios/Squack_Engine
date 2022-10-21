/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: SwapChain.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 21/10/2022 12:30:25													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_SwapChain_CPP_
#define _Sqwack_Engine_SwapChain_CPP_


#pragma once
#include "SwapChain.h"
#include "D3D12LogAssertion.h"

namespace Sqwack
{

	SwapChain::SwapChain(const DXGI_SWAP_CHAIN_DESC& desc):
		m_SwapChainDesc(desc)
	{

	}

	void SwapChain::Init(const DXGI_SWAP_CHAIN_DESC& desc, Microsoft::WRL::ComPtr<IDXGIFactory4> factory4)
	{
		Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory4{ factory4 };
		m_SwapChainDesc = desc;


	}

	SwapChain::~SwapChain()
	{

	}
}





#endif // !_Sqwack_Engine_SwapChain_CPP_

