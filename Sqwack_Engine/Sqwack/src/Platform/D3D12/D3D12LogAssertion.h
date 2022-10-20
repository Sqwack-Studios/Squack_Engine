/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12LogAssertion.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 17/10/2022 17:15:10													 
//==============================================================================//

#ifndef _Sqwack_Engine_D3D12LogAssertion_H_
#define _Sqwack_Engine_D3D12LogAssertion_H_

#pragma once
#include "Sqwack/Core/Assert.h"
#include <winnt.h>


#if SQWACK_DEBUG


#define DXCall(x, hr_) x;\
ASSERT(DXLogCall(hr_, #x, __FILE__, __LINE__));\


#else

#define DXCall(x, hr_) x

#endif

bool DXLogCall(HRESULT hr_, const char* function, const char* file, int line);

#endif // !_Sqwack_Engine_D3D12LogAssertion_H_

