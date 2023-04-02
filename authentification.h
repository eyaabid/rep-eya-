#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <QSqlQuery>
#include "menu.h"
#include <QDialog>

namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();
     void showTime();


private slots:
     void on_pushButton_2_clicked();

     void on_mdp_oubliee_bt_clicked();

private:
      Ui::authentification *ui;
      menu *m = new menu();
};

#endif // AUTHENTIFICATION_H
