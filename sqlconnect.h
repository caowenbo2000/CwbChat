#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#ifndef SQLCONNECT_H
#define SQLCONNECT_H

class Sqlconnect
{
public:
    Sqlconnect();
    ~Sqlconnect();
    bool LoginCheck(int ,QString );//登录查询 api
private:

};


#endif // SQLCONNECT_H
