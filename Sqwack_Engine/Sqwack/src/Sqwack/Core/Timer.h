/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Timer.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 24/10/2022 11:29:44													 
//==============================================================================//

#ifndef _Sqwack_Engine_Timer_H_
#define _Sqwack_Engine_Timer_H_

#pragma once
#include "Core.h"



namespace Sqwack
{


	class Timer
	{
	public:

		virtual ~Timer(){}

		virtual void Start() = 0;
		virtual void Pause() = 0;
		virtual void Resume() = 0;
		//virtual inline const _UINT32& GetElapsedTimeInSeconds() = 0;
		virtual inline const __int64& TimeSinceCreationInMiliseconds() = 0;
		virtual inline const __int64& TimeSincePauseInMiliseconds() = 0;

		//virtual inline float DeltaTime() const = 0;
		//virtual inline float RunningTime() const = 0;

	protected:



	};

}
#endif // !_Sqwack_Engine_Timer_H_

