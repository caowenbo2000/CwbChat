#include "sqlconnect.h"

//QString strr="root";
Sqlconnect::Sqlconnect()
{
//    db.setHostName("47.93.251.155");
//    db.setPort(3306);
//    db.setUserName("root");
//    db.setPassword("root");
//    db.setDatabaseName("ChatTest");
//    if(!db.open())
//    {
//        qDebug()<<"Damn";
//        qDebug()<<db.lastError().text();
//       // QMessageBox::critical( , QObject::tr("Database error"), db.lastError().text());
//        return ;
//    }
//    if(db.open())
//    {
//        qDebug()<<"opened databases";
//    }
//    else
//    {
//        qDebug()<<db.lastError().text();
//        //QMessageBox::critical(this, QObject::tr("Database error"), db.lastError().text());
//    }
}
Sqlconnect::~Sqlconnect()
{
}

bool Sqlconnect::LoginCheck(int Id, QString PassWord)
{
//    if(PassWord.size()>20)
//    {
//        return 0;
//    }
//    QSqlQuery query = QSqlQuery(db);
//    query.exec("use ChatTest;");
//    query.exec(QString("SELECT * FROM User WHERE Id = '%1' and PassWord = '%2';").arg(Id).arg(PassWord));
//    return query.last();
    return 1;
}
