/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Specifications.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 19/10/2022 12:30:41													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_Specifications_H_
#define _Sqwack_Engine_Specifications_H_

#pragma once


namespace Sqwack {




	struct ApplicationSpecification
	{
		std::string       appName{"Sqwack Engine"};
		_UINT16           windowWidth{ 1280 };
		_UINT16           windowHeight{ 720 };
		bool              vsync{ true };
		bool              fullscreen{ false };
		bool              windowDecorated{ true }; //remove borders. //if fullscreen is active, it will override this option
		bool              resizable{ true };
		bool              startMaximized{ false };
	};

	struct WindowSpecification
	{
		std::string windowName{"Sqwack Engine"};
		_UINT16          windowWidth{ 1280 };
		_UINT16          windowHeight{ 720 };
		bool             vsync{ true };
		bool             fullscreen{ false };
		bool             windowDecorated{ true };
	};

	
}

#endif // !_Sqwack_Engine_Specifications_H_

