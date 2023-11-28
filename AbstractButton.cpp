#include "AbstractButton.h"
#include "Globals.h"
#include <iostream>

AbstractButton::AbstractButton() {

}

AbstractButton::AbstractButton(std::string title) {
	title_ = title;
}

AbstractButton::~AbstractButton() {

}

void AbstractButton::setBounds(int x, int y, int width, int height) {
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}
// setLocation 은 위치를 결정하는 함수  (버튼위치만 변경)
void AbstractButton::setLocation(int x, int y) {
	x_ = x;
	y_ = y;
}
// setSize는 크기를 결정하는 함수  (사이즈만 변경)
void AbstractButton::setSize(int width, int height) {
	width_ = width;
	height_ = height;
}

// 버튼을 그리는 함수
void AbstractButton::repaint() {
	if (parent_ != nullptr && parent_->getGraphics() != nullptr) {
		Graphics* g = parent_->getGraphics();
		g->drawRect(x_, y_, width_, height_);
		g->drawString(title_, x_ + 5, y_ + 5);
	}
}

// 스크린 객체 포인터를 저장하는 함수
void AbstractButton::setParent(Screen* scr) {
	parent_ = scr;
}




bool AbstractButton::areYouThere(int x, int y) {
	if (x >= x_ && x <= x_ + width_ && y >= y_ && y <= y_ + height_) {
		return true;
	}
	else {
		return false;
	}
}

std::string AbstractButton::getActionString() {
	return title_;
}