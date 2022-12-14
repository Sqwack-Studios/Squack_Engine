/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: CommandList.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 20/10/2022 14:48:13													 
//==============================================================================//

#ifndef _Sqwack_Engine_CommandList_H_
#define _Sqwack_Engine_CommandList_H_

#pragma once
#include "D3D12Headers.h"

namespace Sqwack
{

	class CommandList
	{
	public:

		CommandList();
		~CommandList();

		static std::unique_ptr<CommandList> Create();

		void TransitionResource(Microsoft::WRL::ComPtr<ID3D12Resource> resource, const D3D12_RESOURCE_STATES& fromState, const D3D12_RESOURCE_STATES& toState);

		void Init(Microsoft::WRL::ComPtr<ID3D12Device> device);
		void Close();

	private:

		Microsoft::WRL::ComPtr<ID3D12CommandAllocator>          m_ID3DCommandAlloc;
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>       m_ID3DCommandList;

	};
}

#endif // !_Sqwack_Engine_CommandList_H_

