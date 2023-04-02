#include "employee.h"
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QSqlQuery>

Employee::Employee()
{
 cin=0;
 nom=" ";
 prenom=" ";
 mail=" ";
 age=0 ;
 postactuelle=" ";
}
 Employee:: Employee(int cin, QString nom, QString prenom,QString mail,int age,QString postactuelle)
 { this->cin=cin;
   this->nom=nom;
   this->prenom=prenom,
   this->mail=mail,
   this->age=age;
   this->postactuelle=postactuelle;


 }
     int Employee::getCin() {return cin;}
     QString Employee::getNom() {return nom;}
     QString Employee::getPrenom() {return prenom;}
     QString Employee::getMail() {return mail;}
     int Employee::getAge(){return age;}
     QString Employee::getPostactuelle() {return postactuelle;}
     void Employee::setCin(int cin){this->cin=cin;}
     void Employee::setNom(QString nom){this->nom=nom;}
     void Employee::setPrenom(QString prenom){this->prenom=prenom;}
     void Employee::setMail(QString mail){this->mail=mail;}
     void Employee::setAge(int age){this->age=age;}
     void Employee::setPostactuelle(QString postactuelle){this->postactuelle=postactuelle;}



     bool Employee :: ajouter()

     { //bool test=false;

         QSqlQuery query;
         QString cin_string=QString::number(cin);
         QString age_string=QString::number(age);
         query.prepare("INSERT INTO EMPLOYEE (CIN, NOM, PRENOM,MAIL,AGE,POSTACTUELLE) "
                       "VALUES (:CIN, :NOM, :PRENOM,:MAIL,:AGE,:POSTACTUELLE)");
         query.bindValue(":CIN", cin_string);
         query.bindValue(":NOM", nom);
         query.bindValue(":PRENOM", prenom);
         query.bindValue(":MAIL", mail);
         query.bindValue(":AGE", age_string);
         query.bindValue(":POSTACTUELLE", postactuelle);
      return query.exec();//execution
     // return test;
     }

bool Employee::supprimer(int cin)
{
  QSqlQuery query;
  query.prepare("Delete from EMPLOYEE where cin=:cin");
  query.bindValue(0, cin);


return query.exec();

}

QSqlQueryModel *Employee::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM EMPLOYEE");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("postactuelle"));

   return model;
}



bool Employee::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEE SET cin=:cin,nom =:nom,prenom =:prenom,mail =:mail,age =:age,postactuelle =:postactuelle WHERE cin=:cin ");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":age", age);
    query.bindValue(":postactuelle", postactuelle);


    return query.exec();
}
QSqlQueryModel* Employee::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
             QString recher="select * from EMPLOYEE where CIN like '%"+rech+"%'";
           model->setQuery(recher);
             return model;
}
QSqlQueryModel *Employee::trier()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT * FROM EMPLOYEE ORDER BY CIN");
              return model;
  }


