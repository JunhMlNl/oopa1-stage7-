#pragma once
#include "Screen.h"
#include "Windows.h"
#include <string>
#include <list>
#include "Etc.h"
#include "Graphics.h"
#include"MyShape.h"
#include "MyRect.h"
#include "MyOval.h"
#include "JCheckBox.h"

class PainterScreen :
    public Screen
{
public:
    PainterScreen();
    PainterScreen(std::wstring, int, int);
    void repaint() override;
    bool eventHandler(MyEvent e) override;
    void initialize() override;
    void setFigType(AbstractButton*);
    void onLButtonDown(MyEvent e) override;
    void onLButtonUp(MyEvent e) override;
private:
    MyShape* myshape[100]; //도형객체
    int numShape = 0; //도형개수 
    MyRect* rect; //임시 사각형 객체
    MyOval* oval; //임시 타원 객체
    int figType_ = 0;  // 1이면 사각형 선택, 2이면 타원 선택으로 사용.
    AbstractButton* tempBtn = nullptr; //클릭했을때 tempBtn에 저장하고 클릭을 띄었을때 클릭했을때의 버튼과 동일한가 다른가를 판단할 때 사용한 변수.
    int startx, starty, endx, endy; //마우스 포인터 위치를 결정하는 임시변수.
    bool checked_;
};
