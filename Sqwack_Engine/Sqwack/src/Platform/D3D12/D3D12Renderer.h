﻿/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: D3D12Renderer.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 21/10/2022 13:00:03													 
//==============================================================================//

#ifndef _Sqwack_Engine_D3D12Renderer_H_
#define _Sqwack_Engine_D3D12Renderer_H_

#pragma once
#include "Platform/Windows/Win32Window.h"
#include "CommandQueue.h"



namespace Sqwack
{
	class CommandQueue;
	class CommandList;

	class D3D12Renderer
	{
	public:

		static void Init();

		
	
		

	private:

		static Win32Window*                           m_noptrWindow;
		static std::unique_ptr<CommandQueue>          m_CommandQueue;

		


	};
}

#endif // !_Sqwack_Engine_D3D12Renderer_H_

