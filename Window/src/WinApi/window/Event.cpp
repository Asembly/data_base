#include "Event.h"
#include<iostream>

void Event::openFile() {
	inputBase_.open(PATH_);
	if (!inputBase_.is_open()) {
		MessageBox(NULL, L"Файл не открыт", L"Failed",MB_OK);
		exit(-1);
	}
}

void Event::handlingMessage(UINT uMsg) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		DestroyWindow(hWnd_);
		break;
	case WM_PAINT:
		hDC_ = BeginPaint(hWnd_, &paintStruct_);
		FillRect(hDC_, &paintStruct_.rcPaint, (HBRUSH)COLOR_WINDOW);
		TextOut(hDC_, 0, 0, L"hello",INFINITY);
		HWND prev = CreateWindow(L"Button", L"Prev", WS_CHILD | WS_VISIBLE,50,350,60,50, hWnd_, NULL, NULL, NULL);
		HWND next = CreateWindow(L"Button", L"Next", WS_CHILD | WS_VISIBLE,375,350,60,50, hWnd_, NULL, NULL, NULL);
		for (int i = 0; !inputBase_.eof(); i++) {
			inputBase_.getline(names_, CHAR_MAX);
			size = strlen(names_)+1;
			unicode = (PWCHAR)calloc(size,sizeof(WCHAR));
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, names_, INFINITE, unicode, size);
			HWND edit = CreateWindow(L"Edit",unicode, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_READONLY |WS_BORDER |ES_CENTER, 0, 0, MAX_WIDTH,MAX_HIGHT - 200, hWnd_, NULL, NULL, NULL);
		}
		break;
	}
}