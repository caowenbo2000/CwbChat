#ifndef SQLITECONNECT_H
#define SQLITECONNECT_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
class SqliteConnect
{
public:
    SqliteConnect();
    void static CreateConversation();  //创建表
    void static InsertRecord(QString); //插入记录
    QSqlQuery static GetRecord(int);
private:
};

#endif // SQLITECONNECT_H
