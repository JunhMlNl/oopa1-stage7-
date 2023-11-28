#pragma once
#include "AbstractButton.h"
#include "PainterScreen.h"

class GridButton :
    public JCheckBox
{
public:
    GridButton();
    GridButton(std::string title);
    void onClick() override;
};

