#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>

namespace Ui {
class textEditor;
}

class textEditor : public QWidget
{
    Q_OBJECT

public:
    explicit textEditor(std::string path, QWidget *parent = nullptr);
    ~textEditor();
    std::string getText();

private slots:
    void on_pushButton_clicked();

private:
    Ui::textEditor *ui;
    std::string path;
};

#endif // TEXTEDITOR_H
