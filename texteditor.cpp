#include "texteditor.h"
#include "ui_texteditor.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

textEditor::textEditor(std::string path, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::textEditor)
{
    ui->setupUi(this);

    this->path = path;


    std::fstream text;


    text.open(path, std::fstream::in);
    if(text)
    {

        std::string temp;
        QString tex = "";
        for( ; std::getline(text, temp) ; )
        {
            tex += QString::fromStdString(temp) + "\n";
        }

    ui->textEdit->setText(tex);


    }
    else
    {
        qDebug() << "ERR FILE";
    }
    text.close();


}

textEditor::~textEditor()
{
    qDebug() << "close";
    std::fstream text;

    text.open(path, std::fstream::out);
    if(text)
    {
        QString temp = ui->textEdit->toPlainText();
        std::string t = temp.toStdString();
        text << t;
    }
    text.close();
    delete ui;
}

void textEditor::on_pushButton_clicked()
{
    qDebug() << "newTest";
}

std::string textEditor::getText()
{
    QString temp = ui->textEdit->toPlainText();
    return temp.toStdString();
}

