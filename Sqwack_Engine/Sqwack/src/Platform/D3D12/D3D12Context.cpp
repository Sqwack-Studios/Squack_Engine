/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Context.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 20/10/2022 17:50:03													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_D3D12Context_CPP_
#define _Sqwack_Engine_D3D12Context_CPP_

#pragma once
#include "D3D12Context.h"

namespace Sqwack
{
	D3D12Context::D3D12Context()
	{

	}

	D3D12Context::~D3D12Context()
	{

	}

	D3D12Context* D3D12Context::Create()
	{
		return new D3D12Context();
	}
}





#endif // !_Sqwack_Engine_D3D12Context_CPP_

