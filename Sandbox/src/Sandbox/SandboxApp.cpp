/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: SandboxApp.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 14/10/2022 14:18:13													 
//==============================================================================//

#ifndef _Sandbox_SandboxApp_CPP_
#define _Sandbox_SandboxApp_CPP_

#pragma once
#include <Sqwack.h>


class Sandbox : public Sqwack::App
{
public:
	Sandbox(const Sqwack::ApplicationSpecification& specs):
		App(specs)
	{

	}

	~Sandbox()
	{

	}
};



Sqwack::App* Sqwack::CreateApp(const Sqwack::ApplicationSpecification& specs)
{
	return new Sandbox(specs);
}






#endif // !_Sandbox_SandboxApp_CPP_

