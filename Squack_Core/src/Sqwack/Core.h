/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Core.h											 
// Author			: Daniel Crespo Muñoz										
// Version			:														     
// Creation time	: 06/10/2022 17:37:52													 
//==============================================================================//

#ifdef SQWACK_PLATFORM_WINDOWS
	#ifdef SQWACK_BUILD_DLL
		#define SQWACK_API __declspec(dllexport)
	#else
		#define SQWACK_API __declspec(dllimport)
	#endif
#else
	#error SQWACK only supports Windows so far!
#endif // SQ_BUILD_DLL


