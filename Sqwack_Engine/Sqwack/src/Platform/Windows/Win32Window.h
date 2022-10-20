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
#include "Platform/D3D12/SwapChain.h"
#include "Platform/D3D12/D3D12Context.h"




namespace Sqwack {

	class SQWACK_API Win32Window: public Window

	{
	public:

		Win32Window(const WindowSpecification& specs);
		virtual ~Win32Window();

		virtual void Init(bool resizable = true, bool maximized = false) override;

		virtual inline _UINT16 GetWidth() const override { return m_Width; } 
		virtual inline _UINT16 GetHeight() const override { return m_Height; }

		virtual inline bool IsVSync() const override { return m_VSync; }
		virtual inline void SetVSync(bool VSync) override { m_VSync = VSync; }

		virtual inline const std::string& GetTitle() override { return m_Title; }
		virtual inline void SetTitle(const std::string& title) override { m_Title = title; }

		virtual void Resize(_UINT16 width, _UINT16 height) override;
		virtual void Fullscreen() override;


		void ProcessMessage(MSG &msg);

	protected:

	private:

		SwapChain                             m_SwapChain;
		std::unique_ptr<D3D12Context>         m_D3D12Context;

	private: 

		static LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
		void RegisterWindowClass();
		HWND CreateWindowHWND();
		
		
		
		
		_UINT16                              m_Width;
		_UINT16                              m_Height;
		std::string                          m_Title;

		bool                                 m_FullScreen;
		bool                                 m_VSync;
		WindowSpecification                  m_Specification;



		//---------Internal Win32 variables--------------------------//

		HWND						         m_HWND;
		//WCHAR						         m_WindowClass[MAX_NAME_STRING];
		//WCHAR						         m_WindowTitle[MAX_NAME_STRING];
		std::wstring				         m_WindowClass;
		std::wstring				         m_WindowTitle;
		//HICON						         m_hIcon;
		static Win32Window*                  m_WindowPtr;
	};	

}
#endif // !_Sqwack_Engine_Win32Window_H_

