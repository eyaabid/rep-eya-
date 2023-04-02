#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include "mainwindow.h"
namespace Ui
{
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

public:
    Ui::menu *ui;
private:
    MainWindow eya;
};

#endif // MENU_H
