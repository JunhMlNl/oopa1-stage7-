#pragma once
#include <iostream>
#include <string>
#include "Screen.h"

class AbstractButton {
public:
	AbstractButton();
	AbstractButton(std::string title);

	virtual void onClick() =0 ;
	virtual ~AbstractButton();
	void setBounds(int x, int y, int width, int height);
	void setLocation(int x, int y);
	void setSize(int width, int height);
	virtual void repaint();
	void setParent(Screen*);
	bool areYouThere(int x, int y);    //해당 위치에 버튼이 있는지 알려주는 함수.
	std::string getActionString();     // 버튼 제목(명령어로 활용)을 돌려주는 함수

protected:  // 나중에 상속을 위해서 protected로 해두자.
	int x_, y_, width_, height_;  // 위치 및 크기
	Screen* parent_;		// screen에 대한 포인터.
	std::string title_;//버튼제목
};
