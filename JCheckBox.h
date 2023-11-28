#pragma once
#include "AbstractButton.h"
#include <string>
#include "Screen.h"
class JCheckBox :
    public AbstractButton
{
public:
    JCheckBox();
    JCheckBox(std::string title);

    bool isCheck(); //JCheckBox�� �ִ� �Լ�
    virtual void onClick() override;
    void repaint() override;
protected:
    bool check_;
};

