#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employee.h"
#include <QMainWindow>
#include <QDirModel>
#include "stat_nb.h"
#include <QPainter>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPrintPreviewDialog>
#include <QUrl>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool controlesaisi();

private slots:
    void on_ajouter_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();

    void on_le_id_cher_cursorPositionChanged(int arg1, int arg2);

    void on_pb_stat_clicked();

    void on_pb_trier_clicked();

    void on_pb_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Employee e;
    Employee tempemploy;
    stat_nb *s;
    int age,cin;
    QString nom,prenom,mail,postactuelle;
};

#endif // MAINWINDOW_H
