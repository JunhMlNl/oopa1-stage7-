#include "PainterButton.h"
#include "PainterScreen.h"
#include "Globals.h"
#include <iostream>


PainterButton::PainterButton() :JButton() {
}

PainterButton::PainterButton(std::string title) : JButton(title) {
}

void PainterButton::onClick() {
	debugPrint(title_);
	((PainterScreen*)(parent_))->setFigType(this); 
}