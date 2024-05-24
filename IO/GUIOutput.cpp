#include "GUIOutput.h"

GUIOutput::GUIOutput(auto *mui)
{
	ui = mui;
}

void GUIOutput::UpdateOutput(string out)
{
    QString qString = QString::fromStdString(out);
    ui->solutionTB->setText(qString);
}

//////////////////////////////////////////////////////////////////////////////////////////
GUIOutput::~GUIOutput()
{
}
