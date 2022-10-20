/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Fence.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 20/10/2022 11:34:35													 
//==============================================================================//

#ifndef _Sqwack_Engine_Fence_H_
#define _Sqwack_Engine_Fence_H_

#pragma once
#include "Sqwack/Core/Core.h"
#include "D3D12Headers.h"

namespace Sqwack
{


	class Fence
	{
	public:
		Fence();
		~Fence();


		void Init(Microsoft::WRL::ComPtr<ID3D12Device> device);

		


	private:
		Microsoft::WRL::ComPtr<ID3D12Fence>                   m_ID3DFence;
		_UINT64                                               m_FenceValue;
		HANDLE                                                m_StallEvent;

		friend class SwapChain;

		//Fence initial value is 0 by default.
		//Not supported custom initial values by now

	};
}
#endif // !_Sqwack_Engine_Fence_H_

