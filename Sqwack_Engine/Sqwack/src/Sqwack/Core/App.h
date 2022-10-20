/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: App.h											 
// Author			: Daniel Crespo Muñoz										
// Version			:														     
// Creation time	: 06/10/2022 17:38:05													 
//==============================================================================//

#ifndef _Sqwack_Engine_App_H_
#define _Sqwack_Engine_App_H_


#pragma once
#include "Sqwack/Core/Core.h"
#include "Sqwack/Core/Specifications.h"
#include "Sqwack/Core/Window.h"



namespace Sqwack {



	class SQWACK_API App
	{

	public:

		App(const ApplicationSpecification& specs);
		virtual ~App();


		void Run();

	private:

		std::unique_ptr<Window>                 m_Window;
		ApplicationSpecification                m_Specification;

	protected:

	
	};

	//To be defined in client
	App* CreateApp(const Sqwack::ApplicationSpecification& specs);
}
#endif // !_Sqwack_Engine_App_H_


