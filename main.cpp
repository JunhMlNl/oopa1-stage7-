
#include "PainterScreen.h"
#include "Screen.h"
#include <iostream>
#include <exception>



// Ŭ���� ����(static)�� �ʱ�ȭ�Ѵ�.
Screen * Screen::mainScreen = new PainterScreen(L"������Ʈ2023", 1000, 800);

int main() {
	try {
		Screen::mainScreen->initialize();
		Screen::mainScreen->eventLoop();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
