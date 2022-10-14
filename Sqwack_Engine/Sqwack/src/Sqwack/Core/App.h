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

namespace Sqwack {

	class SQWACK_API App
	{

	public:

		App();
		virtual ~App();


		void Run();

	private:

	protected:

	
	};

	//To be defined in client
	App* CreateApp();
}
#endif // !_Sqwack_Engine_App_H_


