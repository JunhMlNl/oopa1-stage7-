#include "JCheckBox.h"
#include "JCheckBox.h"
#include "Globals.h"
#include "Graphics.h"
#include <iostream>


JCheckBox::JCheckBox() : AbstractButton() {

}

JCheckBox::JCheckBox(std::string title) : AbstractButton(title), check_(false) {
}

bool JCheckBox::isCheck(){
    return check_;
}

void JCheckBox::onClick(){
    check_ =! check_; 
}


void JCheckBox::repaint(){
    std::string checkboxText = check_ ? "[V]" : "[ ]";
    
    if (parent_ != nullptr && parent_->getGraphics() != nullptr) {
        Graphics* g = parent_->getGraphics();   
        g->drawRect(x_, y_, width_, height_);
        g->drawString(checkboxText + " " + title_, x_ + 5, y_ + 5);
    }
}

