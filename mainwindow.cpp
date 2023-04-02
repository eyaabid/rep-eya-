#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QSqlQuery>
#include<QString>
#include <QIntValidator>
#include <QDirModel>
#include <QtDebug>
#include <QObject>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_Cin_supp->setValidator( new QIntValidator(100, 99999999, this));
    ui->le_Cin_2->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
    ui->le_Age_2->setValidator( new QIntValidator(0, 99, this));
    ui->le_Nom_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_Prenom_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_Postactuelle->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_Cin->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
    ui->le_Age->setValidator( new QIntValidator(0, 99, this));
    ui->le_Nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_Postactuelle_2->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->le_Prenom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
    ui->tab_employee->setModel(e.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::controlesaisi()
{
    QRegExp mailRex("\\b[A-Z,a-z0-9._%+-]+@[A-Z,a-z0-9.-]+\\.[A-Z,a-z]{2,4}\\b");
    mailRex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRex.setPatternSyntax(QRegExp::RegExp);


    if (

                !(ui->le_Nom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

                !(ui->le_Prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||


                ui->le_Cin->text().isEmpty() ||

                ui->le_Cin->text().toInt() == 0 ||

                !(mailRex.exactMatch(ui->le_Mail->text())))



            return 0;

        else

            return 1;


}

void MainWindow::on_ajouter_clicked()
{
    int cin=ui->le_Cin->text().toInt();
    QString nom=ui->le_Nom->text();
    QString prenom=ui->le_Prenom->text();
    QString mail=ui->le_Mail->text();
    int age=ui->le_Age->text().toInt();
    QString postactuelle=ui->le_Postactuelle->text();

   Employee e(cin,nom,prenom,mail,age,postactuelle);
     bool test=controlesaisi();
   if (test)
    test=e.ajouter();
       if(test)
       {
           ui->tab_employee->setModel(e.afficher());
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
      else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       ui->le_Cin->clear();
       ui->le_Nom->clear();
       ui->le_Prenom->clear();
       ui->le_Mail->clear();
       ui->le_Age->clear();
       ui->le_Postactuelle->clear();
}


void MainWindow::on_modifier_clicked()
{
    int cin=ui->le_Cin_2->text().toInt();
        QString nom=ui->le_Nom_2->text();
        QString prenom=ui->le_Prenom_2->text();
        QString mail=ui->le_Mail_2->text();
        int age=ui->le_Age_2->text().toInt();
        QString postactuelle=ui->le_Postactuelle_2->text();
        Employee e (cin,nom,prenom,mail,age,postactuelle);
        bool test=e.modifier();
        if(test){
            ui->tab_employee->setModel(e.afficher());
            QMessageBox::information(nullptr,"modification activite","activite modifie avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","activite non modifie");


         ui->le_Cin->clear();
         ui->le_Nom->clear();
         ui->le_Prenom->clear();
         ui->le_Mail->clear();
         ui->le_Age->clear();
         ui->le_Postactuelle->clear();

}

void MainWindow::on_supprimer_clicked()
{
    Employee e1;
    e1.setCin(ui->le_Cin_supp->text().toInt());
        //bool test=false;
        //bool trouver=e1.verification(e1.getCin());
       // if (trouver)
             bool test=e.supprimer(e1.getCin());
        QMessageBox msgBox;

        if (test)
        {

          msgBox.setText("Supprimer avec succes.");
          ui->tab_employee->setModel(e.afficher());

        }

        else
           msgBox.setText("Echec de suppression");
           msgBox.exec();

           ui->le_Cin_supp->clear();
}

void MainWindow::on_le_id_cher_cursorPositionChanged(int arg1, int arg2)
{
    ui->tab_employee->setModel(tempemploy.rechercher(ui->le_id_cher->text()));

        QString test =ui->le_id_cher->text();

        if(test=="")
        {
            ui->tab_employee->setModel(tempemploy.afficher());//refresh
        }
}

void MainWindow::on_pb_stat_clicked()
{
    s = new stat_nb();
           s->setWindowTitle("statistique par age ");
           s->stats();
           s->show();
}

void MainWindow::on_pb_trier_clicked()
{
    Employee a;
        ui->tab_employee->setModel(tempemploy.trier());
}

void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
                               QTextStream out(&strStream);
                               const int rowCount = ui->tab_employee->model()->rowCount();
                               const int columnCount =ui->tab_employee->model()->columnCount();


                               out <<  "<html>\n"
                                       "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("eleve")
                                       <<  "</head>\n"
                                       "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                           "<h1>Liste des Employees</h1>"

                                           "<table border=1 cellspacing=0 cellpadding=2>\n";

              // headers
             out << "<thead><tr bgcolor=#f0f0f0>";
         for (int column = 0; column < columnCount; column++)
            if (!ui->tab_employee->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_employee->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";
                     // data table
              for (int row = 0; row < rowCount; row++) {
                   out << "<tr>";
          for (int column = 0; column < columnCount; column++) {
           if (!ui->tab_employee->isColumnHidden(column)) {
            QString data = ui->tab_employee->model()->data(ui->tab_employee->model()->index(row, column)).toString().simplified();
              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
          }
         }
                                          out << "</tr>\n";
                                      }
                                      out <<  "</table>\n"
                                          "</body>\n"
                                          "</html>\n";



                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);


                       //QTextDocument document;
                       //document.setHtml(html);
                       QPrinter printer(QPrinter::PrinterResolution);
                       printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setOutputFileName("Employee.pdf");
                       document->print(&printer);
}
