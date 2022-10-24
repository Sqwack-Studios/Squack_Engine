/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Tick.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 24/10/2022 11:43:10													 
//==============================================================================//

#ifndef _Sqwack_Engine_Tick_H_
#define _Sqwack_Engine_Tick_H_

#pragma once
#include "Timer.h"

namespace Sqwack
{
	enum TICK_PLATFORM
	{
		WINDOWS = 0
	};

	class Tick
	{
	
	public:
		
		Tick(const _UINT16& targetFPS, TICK_PLATFORM platform);

		virtual ~Tick() {}

		void StartFrame();
		void EndFrame();
		void Pause();
		void Resume();

		static std::unique_ptr<Tick> Create(const _UINT16& targetFPS);

		inline float GetTargetFrameTimeInMs() const { return m_TargetFrameTimeMS; }
		
		

	private:

		std::unique_ptr<Timer>            m_AppTimer;



		static float                      m_TargetFrameTimeMS;
		

	};

}
#endif // !_Sqwack_Engine_Tick_H_

