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
#include "Platform/D3D12/D3D12Renderer.h"



namespace Sqwack {

	Win32Window* Win32Window::m_SelfWindowPtr = nullptr;

	Win32Window::Win32Window(const WindowSpecification& specs) :
		m_Specification(specs),
		m_Width(specs.windowWidth),
		m_Height(specs.windowHeight),
		m_VSync(specs.vsync),
		m_FullScreen(specs.fullscreen),
		m_HWND(nullptr),
		m_SwapChain(DXGI_SWAP_CHAIN_DESC{})
	{
		m_SelfWindowPtr = this;

		{
			m_WindowClass = m_WindowTitle = std::wstring(specs.windowName.begin(), specs.windowName.end());
			
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
		if (m_HWND)
			ShowWindow(m_HWND, SW_SHOW);

		//Add fullscreen support: fullscreen should resize the swap chains?

		//Add resize support: remember to destroy and resize the swap chain accordingly


		//Create and initialize the context and device
		m_D3D12Context = std::unique_ptr<D3D12Context>(D3D12Context::Create());
		m_D3D12Context->Init();

		//Create and initialize the swap chain
		DXGI_SWAP_CHAIN_DESC scDesc{};
		DXGI_MODE_DESC       bufferDesc{};

		bufferDesc.Width = m_Width;
		bufferDesc.Height = m_Height;
		bufferDesc.RefreshRate.Numerator = 60;
		bufferDesc.RefreshRate.Denominator = 1;
		bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		bufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;

		scDesc.BufferCount = 2;
		scDesc.BufferDesc = bufferDesc;
		scDesc.Windowed = !m_Specification.fullscreen;
		//TODO: 4xMSAA check and support
		scDesc.SampleDesc =  { 1, 0 };
		scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scDesc.OutputWindow = m_HWND;
		scDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		

		//Query for Tearing support in the context object
		scDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;
		/*bufferDesc.RefreshRate = m_D3D12Context*/
		
		m_SwapChain.Init(scDesc, m_D3D12Context->GetFactory4());

		D3D12Renderer::Init();

	}



	LRESULT CALLBACK Win32Window::WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
	{
		
		switch (message)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWnd, message, wparam, lparam);
		}
		return DefWindowProcW(hWnd, message, wparam, lparam);

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
		wcex.lpszClassName = m_WindowClass.c_str();
		wcex.lpszMenuName = nullptr;
		wcex.hInstance = HInstance();
		wcex.lpfnWndProc = Win32Window::WindowProcess;

		HRESULT hr = RegisterClassEx(&wcex);

		assert(SUCCEEDED(hr));
		
	}

	HWND Win32Window::CreateWindowHWND()
	{
		_UINT32 screenWidth = GetSystemMetrics(SM_CXSCREEN);
		_UINT32 screenHeight = GetSystemMetrics(SM_CYSCREEN);

		RECT windowRect{ 0, 0, static_cast<LONG>(m_Width), static_cast<LONG>(m_Height) };

		AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

		_UINT32 windowWidth = windowRect.right - windowRect.left;
		_UINT32 windowHeight = windowRect.bottom - windowRect.top;

		//Center the window within the screen, clamp for (0,0) top-left corner

		_UINT32 screenX = std::max<_UINT32>(0, (screenWidth - windowWidth) / 2);
		_UINT32 screenY = std::max<_UINT32>(0, (screenHeight - windowHeight) / 2);

		std::wstring pepino = L"ciptoe";

		HWND hWnd = CreateWindowExW(
			NULL,
			m_WindowClass.c_str(),
			m_WindowTitle.c_str(),
			WS_OVERLAPPEDWINDOW,
			screenX,
			screenY,
			windowWidth,
			windowHeight,
			NULL,
			NULL,
			HInstance(),
			NULL
		);

		assert(hWnd && "Failed to create WHND");
		
		return hWnd;
	}

	void Win32Window::ProcessMessage(MSG& msg)
	{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
	}


	void Win32Window::Resize(_UINT16 width, _UINT16 height)
	{

	}

	void Win32Window::Fullscreen()
	{

	}

}






#endif // !_Sqwack_Engine_Win32Window_CPP_

