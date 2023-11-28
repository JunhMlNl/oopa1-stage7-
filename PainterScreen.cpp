#include "PainterScreen.h"
#include "PainterButton.h"
#include "GridButton.h"
#include "Etc.h"
#include "Globals.h"

PainterScreen::PainterScreen() :Screen() {
}

PainterScreen::PainterScreen(std::wstring title, int width, int height) : Screen(title, width, height), checked_(false){
}

void PainterScreen::repaint() {
	//버튼그리기.
	Screen::repaint();

	// 도형을 그린다.
	for (int i = 0; i < numShape; i++) {
		myshape[i]->draw();
	}
}

bool PainterScreen::eventHandler(MyEvent e) {
	if (e.isLButtonDownEvent()) {
		// 여기서는 버튼을 클릭한 것인지 확인하고(findButton)
		// 거기에 맞는 액션을 하면 된다.
		// 버튼을 누른것이라면 누른 버튼을 기억시켜야한다.(멤버 변수 사용)   //tempBtn을 사용
		// 아니라면 이전처럼 위치만 기억시킨다.
		tempBtn = findButton(e);

		if (tempBtn == nullptr) {
			onLButtonDown(e);
		}
	}
	else if (e.isLButtonUpEvent()) {
		// 여기서도 버튼을 클릭한 것인지 확인하고(findButton)
		// 거기에 맞는 액션을 하면 된다.
		// 직전에 눌렀던 버튼이라면 (button down 시에 기억) 버튼의 onclick을 호출.
		// 버튼을 눌렀는데 뗄 때는 그 버튼 위치가 아닌 경우,
		// 뗄 때는 버튼인데 누른 버튼과 다르거나 버튼을 누른 적이 없으면 아무 일도 안한다.
		AbstractButton* jb = findButton(e);

		if (jb == nullptr && tempBtn == nullptr) {
			onLButtonUp(e);
		}
		else if (jb == tempBtn) {
			tempBtn->onClick();    //여기서 FigType결정.
			repaint();
		}

		tempBtn = nullptr;
	}
	return false;
}

void PainterScreen::initialize() {
	JButton* jb1 = new PainterButton("사각형");
	addButton(jb1); jb1->setBounds(10, 10, 100, 25); //여긴 수정 안해도 될 것 같음
	JButton* jb2 = new PainterButton("타원");
	addButton(jb2); jb2->setBounds(120, 10, 100, 25);
	JCheckBox* jb3 = new GridButton("그리드");   
	addButton(jb3); jb3->setBounds(230, 10, 100, 25);

}

void PainterScreen::setFigType(AbstractButton* jb) {
	if (jb->getActionString() == "사각형") {
		figType_ = 1;
	}
	else if (jb->getActionString() == "타원") {
		figType_ = 2;
	}
	else if (jb->getActionString() == "그리드") {
		figType_ = 3;
		checked_ = !checked_;
	}
}

void PainterScreen::onLButtonDown(MyEvent e) {
	startx = e.getX();
	starty = e.getY();
}

void PainterScreen::onLButtonUp(MyEvent e) {
	endx = e.getX();
	endy = e.getY();

	if (figType_ == 1) {
		rect = new MyRect(startx, starty, endx, endy, graphics_);
		myshape[numShape++] = rect;
	}
	else if (figType_ == 2) {
		oval = new MyOval(startx, starty, endx, endy, graphics_);
		myshape[numShape++] = oval;
	}
	else if (figType_ == 3) {
		if (checked_) {
			rect = new MyRect((startx/50)*50, (starty/50)*50, (endx/50)*50, (endy/50)*50, graphics_);
			myshape[numShape++] = rect;
		}
		else {
			rect = new MyRect(startx, starty, endx, endy, graphics_);
			myshape[numShape++] = rect;
		}
	}
	invalidate();
}

