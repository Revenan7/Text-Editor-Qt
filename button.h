#ifndef button_H
#define button_H

#include <QPushButton>
#include "mainwindow.h"
#include <filesystem>
#include <stdio.h>

class button : public QPushButton
{
    Q_OBJECT
public:
    button(const std::string& path, const QString& text, MainWindow *parentWindow, QWidget *parent = nullptr);

public slots:
    void onButtonClicked(); // Обработчик клика по кнопке

signals:
    void customButtonClicked(); // Сигнал, который будет испускаться при клике

private:
         // Добавьте свои дополнительные члены класса здесь, если нужно
    std::string path;
    MainWindow *parentWindow;
};

#endif // MYCUSTOMBUTTON_H
