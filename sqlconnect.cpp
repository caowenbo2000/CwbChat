#include "sqlconnect.h"

//QString strr="root";
void  Sqlconnect::MySqlConnect()
{
    QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("47.93.251.155");
    db.setPort(3306);
    db.setUserName("root");
    //str
    db.setPassword("root");
    db.setDatabaseName("ChatTest");
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
       // QMessageBox::critical( , QObject::tr("Database error"), db.lastError().text());
        return ;
    }
    if(db.open())
    {
        qDebug()<<"opened databases";
    }
    else
    {
        qDebug()<<db.lastError().text();
        //QMessageBox::critical(this, QObject::tr("Database error"), db.lastError().text());
    }
}
