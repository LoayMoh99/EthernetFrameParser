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
    QString input = ui->input->text();
    vector<string> frames;
    frames.push_back(input.toStdString());
    return frames;
}

void MainWindow::UpdateOutput(string out){
    ui->solutionTB->setText(QString::fromStdString(out));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_parseBtn_clicked()
{
    ApplicationManager appManager(GUI_IO);
    appManager.SetMainwindowUI(this);

    //Read user action
    appManager.GetUserAction();

    //Exexute the action
    appManager.ExecuteAction();

    //Update the interface
    appManager.UpdateInterface();
}

