/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Win32Window.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 07/10/2022 17:15:00													 
//==============================================================================//

#ifndef _Sqwack_Engine_Win32Window_H_
#define _Sqwack_Engine_Win32Window_H_

#pragma once


#include "Win32Utils.h"
#include "Sqwack/Core/Window.h"



namespace Sqwack {

	class SQWACK_API Win32Window: public Window

	{
	public:

		Win32Window(const UINT16& IDSClassName, const UINT16& IDSWindowTitle, const UINT16& IDIcon, const UINT16& width, const UINT16& height);
		virtual ~Win32Window();

		virtual Win32Window* SpawnWindow();
		bool InitializeWindow();
		
		void ProcessMessage(MSG& msg);

	protected:



	private: 

		static LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
		void CreateWindowClass();
		
		
		
	

		HWND						m_optr_Window;
		WCHAR						m_WindowClass[MAX_NAME_STRING];
		WCHAR						m_WindowTitle[MAX_NAME_STRING];

		UINT16						m_WindowWidth;
		UINT16						m_WindowHeight;

		HICON						m_hIcon;

	};	

}
#endif // !_Sqwack_Engine_Win32Window_H_

