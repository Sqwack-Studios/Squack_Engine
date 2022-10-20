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

		void Init(Microsoft::WRL::ComPtr<ID3D12Device> device, const _UINT16& numBackBuffers);
		void InitCommandListBuffer();

	private:
		Microsoft::WRL::ComPtr<ID3D12CommandQueue>              m_ID3DCommandQueue;

		_UINT8                                                  m_SwapChainBufferCount;


		//The command list is buffer MUST REMAIN FIXED BY THE AMOUNT OF BACK BUFFERS. THIS AMOUNT IS SPECIFIED BY THE SWAP CHAIN
		std::vector<CommandList>                                m_CommandListBuffer;
	};


}
#endif // !_Sqwack_Engine_CommandQueue_H_

