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
        debugPrint("그리드: 체크됨.");
    }
    else {
        debugPrint("그리드: 체크안됨.");
    }
    
    ((PainterScreen*)(parent_))->setFigType(this);
}

