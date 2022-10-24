/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Win32Timer.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 24/10/2022 11:38:00													 
//==============================================================================//

#ifndef _Sqwack_Engine_Win32Timer_H_
#define _Sqwack_Engine_Win32Timer_H_

#pragma once
#include "Platform/Windows/Win32Headers.h"
#include "Sqwack/Core/Timer.h"

namespace Sqwack
{

	class Win32Timer : public Timer
	{

	public:

		Win32Timer();
		virtual ~Win32Timer();

		virtual void Start() override;
		virtual void Pause() override;
		virtual void Resume() override;

		virtual inline const __int64& TimeSinceCreationInMiliseconds() override { return 0; }
		virtual inline const __int64& TimeSincePauseInMiliseconds() override { return 0; }

		
	private:

		double             m_CountPeriod;

		//Member variables are measured in COUNTS

		__int64                        m_SinceCreationCountStamp;
		__int64                        m_PauseTimeCountStamp; //Might be tracked in-loop...



	};
}
#endif // !_Sqwack_Engine_Win32Timer_H_

