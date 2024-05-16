#ifndef BUTTONFOROPENTEXT_H
#define BUTTONFOROPENTEXT_H

#include <QWidget>
#include <fstream>
#include <filesystem>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class ButtonForOpenText;
}

class ButtonForOpenText : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonForOpenText(std::string Openfile, MainWindow *parentWindow, QWidget *parent = nullptr);
    ~ButtonForOpenText();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ButtonForOpenText *ui;
    std::string Openfile;
    MainWindow *parentWindow;

};

#endif // BUTTONFOROPENTEXT_H
