/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: EntryPoint.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 14/10/2022 14:21:59													 
//==============================================================================//

#ifndef _Sqwack_Engine_EntryPoint_H_
#define _Sqwack_Engine_EntryPoint_H_

#pragma once
#include "Sqwack/Core/App.h"

#ifdef SQWACK_PLATFORM_WINDOWS


extern Sqwack::App* Sqwack::CreateApp();


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	#ifdef SQWACK_DEBUG
	//Run the console
	#endif // SQWACK_DEBUG

	auto app = Sqwack::CreateApp();
	app->Run();
	delete app;

	//Parse command line args

}


#else

int main(int argc, char** argv)
{
	//Change compiler settings to run the console
}

#endif


#endif // !_Sqwack_Engine_EntryPoint_H_

