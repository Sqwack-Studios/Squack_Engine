﻿/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Win32Window.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 07/10/2022 18:01:40													 
//==============================================================================//

#include "pch.h"


#ifndef _Sqwack_Engine_Win32Window_CPP_
#define _Sqwack_Engine_Win32Window_CPP_


#pragma once
#include "Win32Window.h"



namespace Sqwack {


	Win32Window::Win32Window(const WindowSpecification& specs) :
		m_Specification(specs),
		m_Width(specs.windowWidth),
		m_Height(specs.windowHeight),
		m_VSync(specs.vsync),
		m_FullScreen(specs.fullscreen)
	
	{
		
		{
			std::wstring wName(specs.windowName.begin(), specs.windowName.end());
			if (specs.windowName.length() > MAX_NAME_STRING - 1)
			{

				wName.copy(&m_WindowTitle[0], MAX_NAME_STRING - 1);
				wName.copy(&m_WindowClass[0], MAX_NAME_STRING - 1);

			}
			else
			{
				wName.copy(&m_WindowTitle[0], specs.windowName.length() + 1);
				wName.copy(&m_WindowClass[0], specs.windowName.length() + 1);
			}
		}

		
	}

	Win32Window::~Win32Window()
	{

	}


	Window* Window::Create(const WindowSpecification& specs)
	{
		return new Win32Window(specs);
	}

	void Win32Window::Init(bool resizable, bool maximized)
	{
		//Create the class
		RegisterWindowClass();

		//Create the window Handler
		m_HWND = CreateWindowHWND();

		//Check for D3D12 support¿?

		//Setup messages callback processing
		
		//Setup resizable and maximized flags
		
		//Create the window

		//Add fullscreen support: fullscreen should resize the swap chains?
		
		//Add resize support: remember to destroy and resize the swap chain accordingly
	}



	LRESULT CALLBACK Win32Window::WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
	{
		switch (message)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			break;
		}


		return DefWindowProc(hWnd, message, wparam, lparam);
	}

	void Win32Window::RegisterWindowClass()
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW; //affects every single instance of this window class
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
		//TODO: App icons
		wcex.hIcon = LoadIcon(NULL, IDI_QUESTION);
		wcex.hIconSm = LoadIcon(NULL, IDI_QUESTION);
		wcex.lpszClassName = m_WindowClass;
		wcex.lpszMenuName = nullptr;
		wcex.hInstance = HInstance();
		wcex.lpfnWndProc = WindowProcess;

		HRESULT hr = RegisterClassEx(&wcex);

		assert(SUCCEEDED(hr));
		
	}

	HWND Win32Window::CreateWindowHWND()
	{

	}

	void Win32Window::ProcessMessage(MSG& msg)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}





}






#endif // !_Sqwack_Engine_Win32Window_CPP_

