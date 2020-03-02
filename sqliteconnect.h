#ifndef SQLITECONNECT_H
#define SQLITECONNECT_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include "msg.h"
class SqliteConnect
{
public:
    SqliteConnect();
    void static CreateConversation();  //创建表
    void static InsertRecord(MsgFormat); //插入记录
    QSqlQuery static GetRecord(int);
private:
};

#endif // SQLITECONNECT_H
