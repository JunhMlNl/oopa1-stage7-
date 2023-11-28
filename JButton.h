#pragma once
#include <string>
#include "Screen.h"
#include "AbstractButton.h"

class JButton :
	public AbstractButton 
{
public:
	JButton();
	JButton(std::string title);
	virtual void onClick() override =0;
	
};
