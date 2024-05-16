#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Create(std::string& path, QString& name);

private slots:


    void on_pushButton_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void onButtonClickced();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
