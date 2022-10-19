/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: App.cpp										
// Author			: Daniel Crespo Muñoz										 
// Version			:														     
// Creation time	: 06/10/2022 18:17:42													 
//==============================================================================//


#include "pch.h"

#ifndef _Sqwack_Engine_App_CPP_
#define _Sqwack_Engine_App_CPP_

#pragma once
#include "Sqwack/Core/App.h"



namespace Sqwack {


	App::App(const ApplicationSpecification& specs):
		m_Specification(specs)
	{
		//initialize the window
	}


	App::~App()
	{

	}

	void App::Run()
	{

		while (true) 
		{
			//First we poll events from the windows msg system

			//Second we update the game loop

			//Third we render
		}
	}
}





#endif // !_Sqwack_Engine_App_CPP_

