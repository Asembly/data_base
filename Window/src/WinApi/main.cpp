#include"Header.h"
#include"window/Win.h"
#include"window/Event.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	Event handling(hwnd,lParam,wParam);
	handling.handlingMessage(uMsg);
	return  DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Window window(nCmdShow);
	window.initWindow(hInstance, WindowProc);
	return 0;
}
