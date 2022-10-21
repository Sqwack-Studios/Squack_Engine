/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Renderer.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 21/10/2022 13:16:51													 
//==============================================================================//

#include "pch.h"

#ifndef _Sqwack_Engine_D3D12Renderer_CPP_
#define _Sqwack_Engine_D3D12Renderer_CPP_

#pragma once
#include "D3D12Renderer.h"

namespace Sqwack
{
	Win32Window* D3D12Renderer::m_noptrWindow{ nullptr };
	std::unique_ptr<CommandQueue> D3D12Renderer::m_CommandQueue{ nullptr };

	void D3D12Renderer::Init()
	{
		//communicate the swap chain with the queues
		// we need the device in order to create the queues
		
		//Obtain a reference to the window containing the swap chain
		m_noptrWindow = Win32Window::m_SelfWindowPtr;
		
		//Create and start the command queue
		m_CommandQueue = CommandQueue::Create();
		m_CommandQueue->Init(m_noptrWindow->GetID3D12DeviceFromContext(), m_noptrWindow->GetSwapChainBufferCount());

		//track the resource heaps and views

	}
}




#endif // !_Sqwack_Engine_D3D12Renderer_CPP_

