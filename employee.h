#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQueryModel>

class Employee
{
public:
    Employee();
    Employee(int Cin,QString Nom, QString Prenom, QString mail,int age, QString postactuelle);
    int getCin();
    QString getNom();
    QString getPrenom();
    QString getMail();
    int getAge();
    QString getPostactuelle();
    void setCin(int);
    void setNom(QString);
    void setPrenom(QString);
    void setMail(QString);
    void setAge(int);
    void setPostactuelle(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* rechercher(QString a);
    bool verification(int);
    QSqlQueryModel *trier();


   private:
    int cin,age;//Cin clé primaire unique et non null
    QString nom, prenom,mail,postactuelle;
};

#endif // EMPLOYEE_H
