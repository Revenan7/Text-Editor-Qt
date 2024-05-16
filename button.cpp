#include "button.h"
#include "mainwindow.h"
#include <filesystem>
#include <iostream>
#include <stdio.h>
#include <fstream>



button::button(const std::string& path, const QString& text, MainWindow *parentWindow, QWidget *parent)
    : QPushButton(text, parent)
{
    // Настройте вашу кнопку здесь
    connect(this, &QPushButton::clicked, this, &button::onButtonClicked);
    this->parentWindow = parentWindow;
    this->path = path;
}

void button::onButtonClicked()
{
    std::filesystem::path temp(path);
    QString name = QString::fromStdString(temp.filename().string());
    parentWindow->Create(path, name);
    // Обработчик клика по кнопке
    emit customButtonClicked(); // Испустить сигнал о клике по вашей кнопке
}
