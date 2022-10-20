/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Fence.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 20/10/2022 11:59:44													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_Fence_CPP_
#define _Sqwack_Engine_Fence_CPP_

#pragma once
#include "Fence.h"
#include "D3D12LogAssertion.h"

namespace Sqwack
{
	Fence::Fence():
		m_FenceValue(0),
		m_ID3DFence(NULL),
		m_StallEvent(NULL)
	{

	}

	Fence::~Fence()
	{

	}

	void Fence::Init(Microsoft::WRL::ComPtr<ID3D12Device> device)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };
		DXCall(HRESULT hr_ = id3dDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_ID3DFence)), hr_);
	}


}






#endif // !_Sqwack_Engine_Fence_CPP_

