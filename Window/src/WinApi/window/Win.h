#include"../Header.h"

class Window
{
private:
	WNDCLASSEX WndClass_ = {sizeof(WndClass_)};
	HWND hWnd_ = {};
	MSG message_ = {};

	const short WIDTH_ = 500;
	const short HEIGHT_ = 500;

	int nCmdShow_;

	const LPCWSTR title_ = L"Application";
public:
	Window(int nCmdShow) {
		nCmdShow_ = nCmdShow;
	}
	void initWindow(HINSTANCE hInstance,LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM));
	void settingWindow(HINSTANCE hInstance);
	void getException();
	void updateWindow();
	HWND getHwnd();
};
