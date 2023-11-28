#include "Screen.h"
#include "Etc.h"
#include "JButton.h"
#include <iostream>
#include "Globals.h"



Screen::Screen() :Screen(L"", 800, 600) {
	// 현재 사용되지 않고 있음.
}

Screen::Screen(std::wstring title, int width, int height) {
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWin", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // 종료 최소화 최대화 아이콘
		WS_THICKFRAME,  // resize가 가능하게
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	graphics_ = new Graphics(hDC_);
	invalidate();
}


// run 함수는 수정하면 위험함.
void Screen::eventLoop() {
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));
	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

void Screen::initialize() {
	// 아직은 할 일이 없음.
}

bool Screen::eventHandler(MyEvent e)
{
	return false;
}

void Screen::repaint() {
	// 여기서 모든 버튼을 그려준다.
	for (int i = 0; i < numButtons; i++) {
		button_[i]->repaint();
	}
}

void Screen::invalidate() {
	// 이 메소드를 부르면 화면을 다시 그리게 된다.
	InvalidateRect(hWnd_, nullptr, true);
	// 다시 말해서 화면이 지워진 다음 repaint함수가 다시 호출된다.
}


Graphics* Screen::getGraphics() {
	return graphics_;
}

void Screen::onLButtonDown(MyEvent e)
{
	debugPrint("이거 호출되면 안됨.");
}

void Screen::onLButtonUp(MyEvent e)
{
	debugPrint("이거 호출되면 안됨.");
}

void Screen::addButton(AbstractButton* jb) {
	// 완성해야함.
	button_[numButtons++] = jb;
	jb->setParent(this);
}

AbstractButton* Screen::findButton(MyEvent e) {
	// 완성해야함.
	for (int i = 0; i < numButtons; i++) {
		AbstractButton* currentButton = button_[i];
		if (currentButton->areYouThere(e.getX(), e.getY())) {
			return currentButton;
		}
	}
	return nullptr;
}