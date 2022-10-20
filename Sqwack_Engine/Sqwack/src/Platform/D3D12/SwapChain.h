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
#include "Platform/Windows/Win32Window.h"

namespace Sqwack 
{
	class SwapChain
	{
	private:

		Microsoft::WRL::ComPtr<IDXGIFactory4>          m_Factory4;
		Fence                                          m_Fence;


	};
}
#endif // !_Sqwack_Engine_SwapChain_H_

