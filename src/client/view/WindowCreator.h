#pragma once

#include <stdexcept>
#include <string>
#include <Windows.h>
#include <d2d1.h>

namespace zs_worldserver {
	

	struct WindowConfig {
		HINSTANCE hInstance;
		int nCmdShow;
		std::wstring winClassName;
		std::string windowName;
	};

	class WindowCreator {
	public:
		WindowCreator(WindowConfig config);
		HWND getWindow();
		void messageLoop();
	private:
		HWND hWindow;
		WindowConfig config;
		void registerWindow();
		void createWindow();
		void showWindow();
		void onPaint();
		LRESULT handleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}