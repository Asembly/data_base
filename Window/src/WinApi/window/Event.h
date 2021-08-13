#include"..\Header.h"
#include<fstream>

class Event
{
private:
	HWND hWnd_ = {};
	HDC hDC_ = {};
	PAINTSTRUCT paintStruct_ = {};
	RECT rect_ = {};

	LPARAM lParam_ = 0;
	WPARAM wParam_ = 0;

	UINT width_;
    UINT height_;

	const int MAX_WIDTH = 500;
	const int MAX_HIGHT = 500;

	std::ifstream inputBase_ = {};
	const char* PATH_ = "Q:/Projects/VisualStudio/C++/WinApi/Window/Window/Window/src/data/dataTeacher";
	char names_[CHAR_MAX];
	LPWSTR unicode;
	DWORD size;
    
public:
	Event(HWND hWnd,LPARAM lParam, WPARAM wParam) {
		this->hWnd_ = hWnd;
		lParam_ = lParam;
		wParam_ = wParam;
		GetWindowRect(hWnd_, &rect_);
		openFile();
		setlocale(LC_ALL, "ru");
	}
	~Event() {
		EndPaint(hWnd_, &paintStruct_);
	}
	void handlingMessage(UINT uMsg);
	void openFile();
};

