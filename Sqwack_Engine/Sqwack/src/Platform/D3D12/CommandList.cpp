/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: CommandList.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 20/10/2022 14:53:55													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_CommandList_CPP_
#define _Sqwack_Engine_CommandList_CPP_

#pragma once
#include "CommandList.h"
#include "D3D12LogAssertion.h"

namespace Sqwack

{
	CommandList::CommandList()
	{

	}

	CommandList::~CommandList()
	{

	}

	std::unique_ptr<CommandList> CommandList::Create()
	{
		return std::make_unique<CommandList>();
	}

	void CommandList::Init(Microsoft::WRL::ComPtr<ID3D12Device> device)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };
		//Create the Command Allocator

		DXCall(HRESULT hr_1 = id3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(m_ID3DCommandAlloc.GetAddressOf())), hr_1);


		//Create the Command List

		DXCall(HRESULT hr_2 = id3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_ID3DCommandAlloc.Get(), nullptr, IID_PPV_ARGS(m_ID3DCommandList.GetAddressOf())), hr_2);

		//Close the Command List ASAP because we will need to Reset(). The command list must be closed before reseting
		m_ID3DCommandList->Close();
	}
}




#endif // !_Sqwack_Engine_CommandList_CPP_

