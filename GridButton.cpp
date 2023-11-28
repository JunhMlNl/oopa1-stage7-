#include "GridButton.h"
#include "PainterScreen.h"
#include "Globals.h"
#include <iostream>


GridButton::GridButton() :JCheckBox() {
}

GridButton::GridButton(std::string title) : JCheckBox(title) {
}

void GridButton::onClick() {
    JCheckBox::onClick();
    if (check_) {
        debugPrint("�׸���: üũ��.");
    }
    else {
        debugPrint("�׸���: üũ�ȵ�.");
    }
    
    ((PainterScreen*)(parent_))->setFigType(this);
}

