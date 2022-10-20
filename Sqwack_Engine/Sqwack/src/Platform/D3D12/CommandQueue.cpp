/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: CommandQueue.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 20/10/2022 14:51:03													 
//==============================================================================//
#include "pch.h"

#ifndef _Sqwack_Engine_CommandQueue_CPP_
#define _Sqwack_Engine_CommandQueue_CPP_

#pragma once
#include "CommandQueue.h"
#include "D3D12LogAssertion.h"

namespace Sqwack
{
	CommandQueue::CommandQueue():
		m_ID3DCommandQueue(nullptr)
		
	{

	}

	CommandQueue::~CommandQueue()
	{

	}


	void CommandQueue::Init(Microsoft::WRL::ComPtr<ID3D12Device> device, const _UINT16& numBackBuffers)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };



		//Create the Command Queue
		D3D12_COMMAND_QUEUE_DESC queueDesc{};
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		queueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;

		DXCall(HRESULT hr_ = id3dDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_ID3DCommandQueue)), hr_);


		//Create as many command list as frames on the fly
		// 
		//Create the Command Allocator

		//DXCall(HRESULT hr_ = id3dDevice->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(m_ID3DCommandAlloc.GetAddressOf())), hr_);


		////Create the Command List

		//DXCall(HRESULT hr_ = id3dDevice->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_ID3DCommandAlloc.Get(), nullptr, IID_PPV_ARGS(m_ID3DCommandList.GetAddressOf())), hr_);

		////Close the Command List ASAP because we will need to Reset(). The command list must be closed before reseting
		//m_ID3DCommandList->Close();

	}
}





#endif // !_Sqwack_Engine_CommandQueue_CPP_

