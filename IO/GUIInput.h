#pragma once
#include "Input.h"
#include <QString>
#include "./../mainwindow.h"


class GUIInput : public Input
{
private:
    MainWindow *ui;

public:
    GUIInput(MainWindow *); // Consturctor

	vector<string> GetUserInput() const;

	~GUIInput();
};
