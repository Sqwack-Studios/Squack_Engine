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
		m_ID3DCommandQueue(nullptr),
		m_ID3DFence(nullptr),
		m_FenceValue(0),
		m_StallEvent(NULL)
	{

	}

	CommandQueue::~CommandQueue()
	{
		::CloseHandle(m_StallEvent);
	}

	std::unique_ptr<CommandQueue> CommandQueue::Create()
	{
		return std::make_unique<CommandQueue>();
	}

	void CommandQueue::Init(Microsoft::WRL::ComPtr<ID3D12Device> device, const _UINT8&  bufferCount)
	{
		Microsoft::WRL::ComPtr<ID3D12Device> id3dDevice{ device };


		{
			//Create the Command Queue
			D3D12_COMMAND_QUEUE_DESC queueDesc{};
			queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
			queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
			queueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;

			DXCall(HRESULT hr_ = id3dDevice->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_ID3DCommandQueue)), hr_);


			//Create as many command list as backbuffers
			m_CommandListBuffer.reserve(bufferCount);
			for (size_t i = 0; i < bufferCount; i++)
			{
				m_CommandListBuffer.push_back(CommandList::Create());
				m_CommandListBuffer[i]->Init(id3dDevice);
			}
		}

		{
			//Setup the fence
			DXCall(HRESULT hr_ = id3dDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_ID3DFence)), hr_);
			CreateEventHandle();
		}
		

	}

	void CommandQueue::SignalFence(const _UINT64& valueToSignal)
	{
		DXCall(HRESULT hr_ = GetID3DCommandQueue()->Signal(GetFence().Get(), GetCurrentFenceValue()), hr_);
	}

	void CommandQueue::FlushCommandQueue()
	{
		//Add an instruction to the command queue to add a new fence point
		SignalFence(AdvanceFenceValue());

		//Wait until the GPU has completed commands up this fence point
		if (GetFence()->GetCompletedValue() < GetCurrentFenceValue())
		{

			//Set the event that the GPU will fire when the fence value is reached
			DXCall(HRESULT hr_ = GetFence()->SetEventOnCompletion(GetCurrentFenceValue(), m_StallEvent), hr_);

			//Wait until the GPU hits the fence
			::WaitForSingleObject(m_StallEvent, INFINITE);
			
		}

	}


	void CommandQueue::CreateEventHandle()
	{
		m_StallEvent = ::CreateEventEx(NULL, FALSE, FALSE, EVENT_ALL_ACCESS);
	}


}





#endif // !_Sqwack_Engine_CommandQueue_CPP_

