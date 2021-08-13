#include "Win.h"
#include<iostream>


void Window::settingWindow(HINSTANCE hInstance) {
	WndClass_.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass_.hIcon = (HICON)LoadImage(hInstance, L"icon.ico", IMAGE_ICON, 32, 32, 0);
	WndClass_.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass_.style = CS_HREDRAW | CS_VREDRAW;

	WndClass_.lpszClassName = L"window/x64";
}

void Window::updateWindow() {
	ShowWindow(getHwnd(), nCmdShow_);
	UpdateWindow(getHwnd());

	while(GetMessage(&message_, NULL,0,0)) {
		TranslateMessage(&message_);
		DispatchMessage(&message_);
	}
}

void Window::initWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM)) {
	WndClass_.lpfnWndProc = WndProc;
	WndClass_.hInstance = hInstance;
	settingWindow(hInstance);

	RegisterClassEx(&WndClass_);

	hWnd_ = CreateWindow(WndClass_.lpszClassName, title_, WS_OVERLAPPEDWINDOW, 0, 0, WIDTH_, HEIGHT_, NULL, NULL, hInstance, NULL);

	try {
		getException();
		updateWindow();
	}
	catch (std::exception &e) {
		MessageBox(NULL, L"Failed to create window", L"Error", MB_OK);
		DestroyWindow(hWnd_);
		PostQuitMessage(0);
	}
}

void Window::getException() {
	if (hWnd_ == NULL) {
		throw std::exception("HWND - error");
	}
}
HWND Window::getHwnd() {
	return hWnd_;
}