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
#include "pch.h"
#include "Sqwack/Core/App.h"

#ifdef SQWACK_PLATFORM_WINDOWS


extern Sqwack::App* Sqwack::CreateApp();


int CALLBACK wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	#ifdef SQWACK_DEBUG
	//Run the console
	#endif // SQWACK_DEBUG

	//Maybe call a common "StartApp()" function for bot main entry points

	//Parse command line args
	auto app = Sqwack::CreateApp();
	app->Run();
	delete app;


}


#else

int main(int argc, char** argv)
{
	//Change compiler settings to run the console
}

#endif


#endif // !_Sqwack_Engine_EntryPoint_H_

