#pragma once
#include <wtypes.h>

namespace Elion
{
	struct WindowSize
	{
		unsigned int Width;
		unsigned int Height;
	};



	class WindowProperties
	{
	private:

		WindowSize m_WSize;
		RECT rect;
		HWND hwnd = GetDesktopWindow();
	public:

		WindowSize size()
		{
			
			if (GetWindowRect(hwnd, &rect))
			{
				m_WSize.Width = rect.right - rect.left;
				m_WSize.Height = rect.bottom - rect.top;
			}

			return m_WSize;
		}


	};

	
}