/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: SwapChain.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 20/10/2022 14:40:15													 
//==============================================================================//

#ifndef _Sqwack_Engine_SwapChain_H_
#define _Sqwack_Engine_SwapChain_H_

#pragma once
#include "D3D12Headers.h"
#include "Fence.h"
#include "CommandQueue.h"
#include "Descriptor.h"




namespace Sqwack 
{
	

	class SwapChain
	{
	public:

		
		SwapChain();
		~SwapChain();

	
		
		SwapChain& operator= (const SwapChain& swapChain) = delete;
		SwapChain(const SwapChain& swapchain) = delete;
		



		void Init(Microsoft::WRL::ComPtr<IDXGIFactory4> factory4, Microsoft::WRL::ComPtr<ID3D12Device> device);
		void CreateSwapChain(Microsoft::WRL::ComPtr<IDXGIFactory4> factory4, Microsoft::WRL::ComPtr<ID3D12Device> device, DXGI_SWAP_CHAIN_DESC& desc);

		/*static inline const _UINT8 GetCurrentBackBuffer()  { return Win32Window::GetCurrentBackBuffer(); }*/
		static inline const _UINT8 GetNumBackBuffers()  { return Window::BackBufferCount; }

		inline _UINT8 GetCurrentBackBuffer() const  { return m_CurrentBackBuffer; }


	private:

		_UINT8                                         m_CurrentBackBuffer;


		Fence                                          m_Fence;

		Microsoft::WRL::ComPtr<IDXGISwapChain>         m_SwapChain;
		DXGI_SWAP_CHAIN_DESC                           m_SwapChainDesc;


		std::unique_ptr<Descriptor>                    m_Descriptor;
		std::unique_ptr<CommandQueue>                  m_CommandQueue;




	};
}
#endif // !_Sqwack_Engine_SwapChain_H_

