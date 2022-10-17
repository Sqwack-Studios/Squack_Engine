/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Assert.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 17/10/2022 16:57:51													 
//==============================================================================//

#ifndef _Sqwack_Engine_Assert_H_
#define _Sqwack_Engine_Assert_H_

#pragma once
#include "Sqwack/Core/Core.h"



//---------- ASERTION MACRO -----------//
#if SQWACK_DEBUG
	#define ASSERT(x) if(!(x)) __debugbreak()
#else 
	#define ASSERT(x)	x
#endif


//------------ DIRECTX 12 ASSERTIONS --------- //
#include "Platform/D3D12/D3D12LogAssertion.h"



#endif // !_Sqwack_Engine_Assert_H_

