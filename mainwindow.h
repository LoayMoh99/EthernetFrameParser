#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IO/Input.h"
#include "IO/Output.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Input, public Output
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // I/O Functions
    vector<string> GetUserInput() const;
    void UpdateOutput(string);

private slots:
    void on_parseBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
