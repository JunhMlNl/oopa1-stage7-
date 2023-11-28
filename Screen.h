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
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;	 // ���� �ڵ��� �����صд�.
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.
	Graphics* graphics_;
public:
	static Screen* mainScreen;	// ���� ���� ��� static ���� �Ѵ�.

	Screen();
	Screen(std::wstring, int, int);
	void eventLoop();

	Graphics* getGraphics();
	virtual bool eventHandler(MyEvent e);
	virtual void repaint();
	void invalidate();	// ������ ȭ���� �ٽ� �׷������ϴ� �������� �˸�.
	virtual void initialize();  // Must override

	// GUI �� ���� �Լ�
	void addButton(AbstractButton*);
	AbstractButton* findButton(MyEvent e);	// ��ư�� areYouThere �Լ��� �̿��ؼ� ã�� �Լ�

private:
	// GUI�� ���� ���� ����
	AbstractButton* button_[100];
	int numButtons = 0;
	// ������ ���� ���� ����
private:
	// �ӽ� ����
public:
	virtual void onLButtonDown(MyEvent e);
	virtual void onLButtonUp(MyEvent e);
};