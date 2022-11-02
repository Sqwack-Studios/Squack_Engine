/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: CommandQueue.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 20/10/2022 14:48:07													 
//==============================================================================//

#ifndef _Sqwack_Engine_CommandQueue_H_
#define _Sqwack_Engine_CommandQueue_H_

#pragma once
#include "D3D12Headers.h"
#include "CommandList.h"

namespace Sqwack
{ 
	class CommandQueue
	{
	public:
		CommandQueue();
		~CommandQueue();

		static std::unique_ptr<CommandQueue> Create();


		void Init(Microsoft::WRL::ComPtr<ID3D12Device> device, const _UINT8& bufferCount);
		inline Microsoft::WRL::ComPtr<ID3D12CommandQueue>  GetID3DCommandQueue() const { return m_ID3DCommandQueue; }
		inline CommandList* GetCommandList(const _UINT8 &indexBuffer) { return m_CommandListBuffer[indexBuffer].get(); }

	public:

		void FlushCommandQueue();
		

	private:
		Microsoft::WRL::ComPtr<ID3D12CommandQueue>              m_ID3DCommandQueue;

		//The command list is buffer MUST REMAIN FIXED BY THE AMOUNT OF BACK BUFFERS. THIS AMOUNT IS SPECIFIED BY THE SWAP CHAIN

		std::vector<std::unique_ptr<CommandList>>               m_CommandListBuffer;

	private:

		Microsoft::WRL::ComPtr<ID3D12Fence>                     m_ID3DFence;
		_UINT64                                                 m_FenceValue;
		HANDLE                                                  m_StallEvent;

		inline Microsoft::WRL::ComPtr<ID3D12Fence> GetFence() const { return m_ID3DFence; }

		void CreateEventHandle();
		inline const _UINT64& AdvanceFenceValue() { return ++m_FenceValue; }
		inline const _UINT64& GetCurrentFenceValue() { return m_FenceValue; }
		void SignalFence(const _UINT64& valueToSignal);


		


	

	};


}
#endif // !_Sqwack_Engine_CommandQueue_H_

