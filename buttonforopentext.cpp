#include "buttonforopentext.h"
#include "ui_buttonforopentext.h"
#include "mainwindow.h"
#include "texteditor.h"
#include <fstream>
#include <filesystem>
#include "texteditor.h"


ButtonForOpenText::ButtonForOpenText(std::string Openfile, MainWindow *parentWindow, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ButtonForOpenText)
{
    ui->setupUi(this);
    this->Openfile = Openfile;
    this->parentWindow = parentWindow;




}

ButtonForOpenText::~ButtonForOpenText()
{
    delete ui;
}

void ButtonForOpenText::on_pushButton_clicked()
{

}

