#include "prisonniers.h"
#include <QDebug>
#include <QDate>


 Prisonniers:: Prisonniers()

{
id_priso="";
nom_priso="";
prenom_priso="";
crime = "";
CIN_priso = 0;
age =0;
}


 Prisonniers::Prisonniers (QString nom_priso,QString prenom_priso , QString id_priso , QString crime , int CIN_priso , int age)
{
  this->nom_priso=nom_priso;
  this->prenom_priso=prenom_priso;
  this->id_priso=id_priso;
  this -> crime = crime ;
  this -> CIN_priso = CIN_priso;
  this -> age = age ;


}


bool Prisonniers::ajouter()
{
QSqlQuery query;
//QString res= QString::number(id);
query.prepare("INSERT INTO Prisonniers (ID, NOM, PRENOM,crime, CIN ,Age ) "
                    "VALUES (:id_priso, :nom_priso, :prenom_priso, :crime, :CIN_priso, :age)");
query.bindValue(":id_priso", id_priso);
query.bindValue(":nom_priso", nom_priso);
query.bindValue(":prenom_priso", prenom_priso);
query.bindValue(":crime", crime);
query.bindValue(":CIN_priso", CIN_priso);
query.bindValue(":age", age);

return    query.exec();
}

QSqlQueryModel *  Prisonniers::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  Prisonniers");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("crime"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Age"));
    return model;
}


bool Prisonniers::supprimer (QString idd)
{
QSqlQuery query;
//QString res= QString::number(idd);
query.prepare("Delete from  Prisonniers where ID = :id_priso ");
query.bindValue(":id_priso", idd);
return query.exec();
}



bool  Prisonniers::modifier()
{
    QSqlQuery query;

       query.prepare("UPDATE  Prisonniers SET NOM =:nom_priso, PRENOM =:prenom_priso ,crime=:crime , CIN =:CIN_priso WHERE ID=:id_priso");
       query.bindValue(":id_priso", id_priso);
       query.bindValue(":nom_priso", nom_priso);
       query.bindValue(":prenom_priso", prenom_priso);
       query.bindValue(":crime", crime);
       query.bindValue(":CIN_priso", CIN_priso);

    return query.exec();
}
