/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Win32Timer.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 24/10/2022 12:33:59													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_Win32Timer_CPP_
#define _Sqwack_Engine_Win32Timer_CPP_

#pragma once
#include "Platform/Windows/Win32Timer.h"

namespace Sqwack
{
	Win32Timer::Win32Timer():
		m_SinceCreationCountStamp(0),
		m_PauseTimeCountStamp(0)
	{
		__int64 countFreq;
		QueryPerformanceFrequency((LARGE_INTEGER*)&countFreq);

		m_CountPeriod = 1 /static_cast<double>(countFreq);

	}

	void Win32Timer::Start()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&m_SinceCreationCountStamp);
	}

	void Win32Timer::Pause()
	{

	}

	void Win32Timer::Resume()
	{

	}
}




#endif // !_Sqwack_Engine_Win32Timer_CPP_

