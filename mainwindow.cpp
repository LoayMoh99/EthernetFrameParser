#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ApplicationManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAutoFillBackground( true );
}


vector<string>  MainWindow::GetUserInput() const{
    QStringList qStringInputList = ui->input->text().split(',');
    vector<string> frames;
    for (const QString& qString : qStringInputList) {
        if(!qString.isEmpty())
            frames.push_back(qString.toStdString());
    }
    return frames;
}

void MainWindow::UpdateOutput(string out){
    // concatenate the output
    QString concatenatedOut = ui->solutionTB->toPlainText() + QString::fromStdString(out);
    ui->solutionTB->setText(concatenatedOut);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_parseBtn_clicked()
{
    // clear the output
    ui->solutionTB->clear();

    ApplicationManager appManager(GUI_IO);
    appManager.SetMainwindowUI(this);

    // Read user action (setup the action to be GUI_IO)
    appManager.GetUserAction();

    //Exexute the action
    appManager.ExecuteAction();

    //Update the interface
    appManager.UpdateInterface();
}

