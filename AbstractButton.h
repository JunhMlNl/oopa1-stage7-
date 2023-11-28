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
	bool areYouThere(int x, int y);    //�ش� ��ġ�� ��ư�� �ִ��� �˷��ִ� �Լ�.
	std::string getActionString();     // ��ư ����(��ɾ�� Ȱ��)�� �����ִ� �Լ�

protected:  // ���߿� ����� ���ؼ� protected�� �ص���.
	int x_, y_, width_, height_;  // ��ġ �� ũ��
	Screen* parent_;		// screen�� ���� ������.
	std::string title_;//��ư����
};
