#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#ifndef SQLCONNECT_H
#define SQLCONNECT_H


class Sqlconnect
{
public:
    Sqlconnect();
    ~Sqlconnect();
    static void MySqlConnect();
private:
    QString str="root";
    //QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");
 
};

#endif // SQLCONNECT_H
