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
	#ifdef SQWACK_DYNAMIC_LINK
		#ifdef SQWACK_BUILD_DLL
			#define SQWACK_API __declspec(dllexport)
		#else
			#define SQWACK_API __declspec(dllimport)
		#endif
	#else
		#define SQWACK_API
	#endif
#else
	#error SQWACK only supports Windows so far!
#endif // SQ_BUILD_DLL





#include <stdint.h>
#include <string>




namespace Sqwack {

	/*typedef std::string				String;*/

	/*  ----- INTEGERS ------  */
	//unsigned ints standards
	typedef uint8_t					_UINT8;
	typedef uint16_t				_UINT16;
	typedef uint32_t				_UINT32;
	typedef uint64_t				_UINT64;

	
	//signed ints
	typedef int8_t					_INT8;
	typedef int16_t					_INT16;
	typedef int32_t					_INT32;
	typedef int64_t					_INT64;
	 
	
}

