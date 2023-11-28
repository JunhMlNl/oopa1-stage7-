#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Etc.h"
#include "Graphics.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class AbstractButton;
class Screen {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;	 // 윈도 핸들을 저장해둔다.
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.
	Graphics* graphics_;
public:
	static Screen* mainScreen;	// 전역 변수 대신 static 으로 한다.

	Screen();
	Screen(std::wstring, int, int);
	void eventLoop();

	Graphics* getGraphics();
	virtual bool eventHandler(MyEvent e);
	virtual void repaint();
	void invalidate();	// 현재의 화면이 다시 그려져야하는 상태임을 알림.
	virtual void initialize();  // Must override

	// GUI 를 위한 함수
	void addButton(AbstractButton*);
	AbstractButton* findButton(MyEvent e);	// 버튼의 areYouThere 함수를 이용해서 찾는 함수

private:
	// GUI를 위한 변수 선언
	AbstractButton* button_[100];
	int numButtons = 0;
	// 응용을 위한 변수 선언
private:
	// 임시 변수
public:
	virtual void onLButtonDown(MyEvent e);
	virtual void onLButtonUp(MyEvent e);
};