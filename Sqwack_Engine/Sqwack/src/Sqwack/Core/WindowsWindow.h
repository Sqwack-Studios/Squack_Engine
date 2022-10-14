/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: WindowsWindow.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 07/10/2022 17:15:00													 
//==============================================================================//

#ifndef _Sqwack_Engine_WindowsWindow_H_
#define _Sqwack_Engine_WindowsWindow_H_

#pragma once


#include "WindowsUtils.h"




#define HInstance() GetModuleHandle(NULL)
#define MAX_NAME_STRING 256

namespace Sqwack {

	class SQWACK_API WindowsWindow

	{
	public:

		WindowsWindow(const UINT16& IDSClassName, const UINT16& IDSWindowTitle, const UINT16& IDIcon, const UINT16& width, const UINT16& height);
		virtual ~WindowsWindow();

		virtual WindowsWindow* SpawnWindow();
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
#endif // !_Sqwack_Engine_WindowsWindow_H_

