#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QtDebug>
#include "authentification.h"
#include "ui_authentification.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/ACER/gestion_accuser - Copie/court backg.png");
     //ui->label_2->setPixmap(pix);
}

menu::~menu()
{
    delete ui;
}


void menu::on_pushButton_1_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
}

void menu::on_pushButton_2_clicked()
{
    qDebug()<<"WELCOME  mahmoud  ";
       eya.show();
}

void menu::on_pushButton_3_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME yassine"),
                                   QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}

void menu::on_pushButton_4_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME dhiae"),
                                   QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}
