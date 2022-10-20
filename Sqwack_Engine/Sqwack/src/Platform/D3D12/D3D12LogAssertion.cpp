/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12LogAssertion.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 17/10/2022 17:22:08													 
//==============================================================================//
#include "pch.h"


#ifndef _Sqwack_Engine_D3D12LogAssertion_CPP_
#define _Sqwack_Engine_D3D12LogAssertion_CPP_



#pragma once
#include "D3D12Headers.h"
#include "D3D12LogAssertion.h"



bool DXLogCall(HRESULT hr_, const char* function, const char* file, int line)
{
	if (!SUCCEEDED(hr_))
	{
		_com_error error(hr_);
		std::string_view _func{ function };
		std::string_view _file{ file };
		

		std::cout << "[DirectX 12 Assertion]  " << _func << " failed in " << _file << " ; line " << line << " ; error: " << error.ErrorMessage() << std::endl;
		return false;
	}
	return true;
	
}




#endif // !_Sqwack_Engine_D3D12LogAssertion_CPP_


