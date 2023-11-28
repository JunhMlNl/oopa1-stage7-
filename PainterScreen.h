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
    MyShape* myshape[100]; //������ü
    int numShape = 0; //�������� 
    MyRect* rect; //�ӽ� �簢�� ��ü
    MyOval* oval; //�ӽ� Ÿ�� ��ü
    int figType_ = 0;  // 1�̸� �簢�� ����, 2�̸� Ÿ�� �������� ���.
    AbstractButton* tempBtn = nullptr; //Ŭ�������� tempBtn�� �����ϰ� Ŭ���� ������� Ŭ���������� ��ư�� �����Ѱ� �ٸ����� �Ǵ��� �� ����� ����.
    int startx, starty, endx, endy; //���콺 ������ ��ġ�� �����ϴ� �ӽú���.
    bool checked_;
};
