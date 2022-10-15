/*===============================================================================/
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


	Win32Window::Win32Window(const UINT16& IDSClassName, const UINT16& IDSWindowTitle, const UINT16& IDIcon, const UINT16& width, const UINT16& height):
		m_WindowWidth(width),
		m_WindowHeight(height),
		m_optr_Window(nullptr)
	{
		LoadString(HInstance(), IDSWindowTitle, m_WindowTitle, MAX_NAME_STRING);
		LoadString(HInstance(), IDSClassName, m_WindowClass, MAX_NAME_STRING);
		m_hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDIcon));
	}
	Win32Window::~Win32Window()
	{
	}


	Win32Window* Win32Window::SpawnWindow()
	{
		if (m_optr_Window)
		{
			ShowWindow(m_optr_Window, SW_SHOW);
			return this;
			
		}
		return nullptr;
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

	void Win32Window::CreateWindowClass()
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;

		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));

		wcex.hIcon = m_hIcon;
		wcex.hIconSm = m_hIcon;

		wcex.lpszClassName = m_WindowClass;

		wcex.lpszMenuName = nullptr;

		wcex.hInstance = HInstance();

		wcex.lpfnWndProc = WindowProcess;

		RegisterClassEx(&wcex);
	}

	void Win32Window::ProcessMessage(MSG& msg)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}




	bool Win32Window::InitializeWindow()
	{

		CreateWindowClass();

		m_optr_Window = CreateWindow(
			m_WindowClass,
			m_WindowTitle,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			0,
			m_WindowWidth,
			m_WindowHeight,
			nullptr,
			nullptr,
			HInstance(),
			nullptr
		);

		
		if (m_optr_Window)		return true;

		
		MessageBox(0, L"Failed to create Window!", 0, 0);
		return false;
		
	}


}






#endif // !_Sqwack_Engine_Win32Window_CPP_

