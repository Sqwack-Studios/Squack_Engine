/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Window.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 15/10/2022 11:57:02													 
//==============================================================================//

#ifndef _Sqwack_Engine_Window_H_
#define _Sqwack_Engine_Window_H_

#pragma once
#include "Sqwack/Core/Specifications.h"


namespace Sqwack {

	class Window
	{
	public:

		virtual ~Window() {};

		virtual void Init(bool resizable = true, bool maximized = false) = 0;

		virtual inline _UINT16 GetWidth() const = 0;
		virtual inline _UINT16 GetHeight() const = 0;

		virtual inline bool IsVSync() const = 0;
		virtual inline void SetVSync(bool VSync) = 0;

		virtual inline const std::string& GetTitle() = 0;
		virtual inline void SetTitle(const std::string& title) = 0;

		virtual void Resize(_UINT16 width, _UINT16 height) = 0;
		virtual void Fullscreen() = 0;

		virtual void ProcessMessage(MSG& msg) = 0;

		static Window* Create(const WindowSpecification& specs);


		static constexpr _UINT8         BackBufferCount{ 2 };

	protected:


		

	};

}
#endif // !_Sqwack_Engine_Window_H_

