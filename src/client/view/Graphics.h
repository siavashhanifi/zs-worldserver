#pragma once

#include <Windows.h>
#include <d2d1.h>

namespace zs_worldserver {
	class Graphics {
	public:
		Graphics();
	private:
		HWND window;
		ID2D1Factory* pFactory;
		ID2D1HwndRenderTarget* pRenderTarget;
		ID2D1SolidColorBrush* pBrush;
		D2D1_ELLIPSE            ellipse;

		void    CalculateLayout();
		HRESULT CreateGraphicsResources();
		void    DiscardGraphicsResources();
		void    OnPaint();
		void    Resize();
	};
}