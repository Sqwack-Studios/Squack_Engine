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



#include "pch.h"
#include <string>
#include <stdint.h>
#include "App.h"



namespace Sqwack {

	/*typedef std::string				String;*/

	/*  ----- INTEGERS ------  */
	//unsigned ints standards
	typedef uint8_t					UINT8;
	typedef uint16_t				UINT16;
	typedef uint32_t				UINT32;
	typedef uint64_t				UINT64;

	//signed ints
	typedef int8_t					INT8;
	typedef int16_t					INT16;
	typedef int32_t					INT32;
	typedef int64_t					INT64;
	 
	
}

