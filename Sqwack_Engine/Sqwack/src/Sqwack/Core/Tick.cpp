/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Tick.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 24/10/2022 11:45:36													 
//==============================================================================//
#include "pch.h"


#ifndef _Sqwack_Engine_Tick_CPP_
#define _Sqwack_Engine_Tick_CPP_

#pragma once
#include "Tick.h"
#include "Platform/Windows/Win32Timer.h"


namespace Sqwack
{
	float Tick::m_TargetFrameTimeMS = 0;

	Tick::Tick(const _UINT16& targetFPS, TICK_PLATFORM platform):
		m_AppTimer(nullptr)
	{

		switch (platform)
		{
		case Sqwack::WINDOWS:
			m_AppTimer = std::make_unique<Win32Timer>();
			break;
		default:
			break;
		}

	}
	
	std::unique_ptr<Tick> Tick::Create(const _UINT16& targetFPS)
	{

#ifdef SQWACK_PLATFORM_WINDOWS

		
		return std::make_unique<Tick>(targetFPS, TICK_PLATFORM::WINDOWS);

#endif // SQWACK_PLATFORM_WINDOWS


		
	}


}




#endif // !_Sqwack_Engine_Tick_CPP_

