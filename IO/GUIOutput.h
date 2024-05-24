#pragma once
#include "Output.h"
#include <QString>
#include "./../mainwindow.h"

class GUIOutput : public Output
{
private:
    Ui::MainWindow *ui;

public:
    GUIOutput(Ui::MainWindow *); // Consturctor
	void UpdateOutput(string);
	~GUIOutput();
};
