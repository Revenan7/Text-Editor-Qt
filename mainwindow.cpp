#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QTextEdit>
#include "texteditor.h"
#include <filesystem>
#include <QVBoxLayout>
#include "buttonforopentext.h"
#include "button.h"


QString str1;
std::string pathFiles = "R:/textFiles";
int cFiles{};

namespace fs = std::filesystem;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<std::string> source;

    for(const auto& i : fs::directory_iterator(pathFiles))
    {
        if(i.is_regular_file())
        {
            cFiles++;

            source.push_back(i.path().string());
        }
    }



    qDebug() << cFiles;
    int w{50};




    for(const auto& i : source)
    {

        fs::path temp(i);
        QString t = QString::fromStdString(temp.filename().string());
        button *buttonC = new button(i, t, this, ui->tabWidget->widget(0));
        buttonC->setGeometry(10, w, 150, 30);  // Установите координаты и размеры кнопки
        connect(buttonC, &button::clicked, this, &MainWindow::onButtonClickced);  // Подключение сигнала нажатия кнопки к слоту
        w+=50;
        buttonC -> show();

    }

}

void MainWindow::onButtonClickced()
{
    qDebug() << "test";
}

MainWindow::~MainWindow()
{
    qDebug() << "close";
    std::fstream text;
    std::string path = "R:/test.txt";


    delete ui;
}

void MainWindow::Create(std::string& path, QString& name)
{
    ui->tabWidget->addTab(new textEditor(path), name);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}



void MainWindow::on_pushButton_clicked()
{

    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    qDebug() << "test";
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QString nameQ = ui->tabWidget->tabText(index);
    std::string nameF = nameQ.toStdString();
    std::string name = pathFiles + "/" + nameF;

    textEditor *editor = qobject_cast<textEditor *>(ui->tabWidget->widget(index));


    std::fstream text;
    text.open(name, std::fstream::out);
    if(text)
    {

        std::string t = editor->getText();
        text << t;
    }


    ui->tabWidget->removeTab(index);

}

