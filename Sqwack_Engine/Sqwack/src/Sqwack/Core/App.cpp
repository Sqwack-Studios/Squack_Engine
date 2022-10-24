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
		m_Specification(specs),
		m_Window(nullptr),
		m_Tick(nullptr)
	{
		//initialize the window
		m_Window = std::unique_ptr<Window>(Window::Create(WindowSpecification()));
		m_Window->Init();

		m_Tick = std::unique_ptr<Tick>(Tick::Create(specs.targetFPS));
	}


	App::~App()
	{

	}

	void App::Run()
	{
		
		MSG msg{};
		PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE);
		while (msg.message != WM_QUIT) 
		{
			//First we poll events from the windows msg system
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				m_Window->ProcessMessage(msg);
			}
			

			//Second we update the game loop

			//Third we render
		}
	}
}





#endif // !_Sqwack_Engine_App_CPP_

