#include "sqliteconnect.h"
#include <QDebug>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>
#include <QSqlRecord>
#include <QDateTime>

SqliteConnect::SqliteConnect() // 连接数据库
{
    QSqlDatabase SqliteDB ;
    SqliteDB = QSqlDatabase :: addDatabase("QSQLITE");
    if(!SqliteDB.isValid())
    {
        qDebug() << SqliteDB.lastError() ;
        return ;
    }

    //const QDir test = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    //qDebug() << test.absolutePath() ;
    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);//定义安装路径C:/Users/caowenbo/AppData/Roaming/chapter5-styling/chat-database.sqlite3
    if (!writeDir.mkpath("."))//创建该目录 若存在bool = 1
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

    //Ensure that we have a writable location on all devices.
    const QString fileName = writeDir.absolutePath() + "/CwbChat.sqlite3";
    qDebug() << fileName ;
    //When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
    SqliteDB.setDatabaseName(fileName);
    if (!SqliteDB.open()) {
        qFatal("Cannot open database: %s", qPrintable(SqliteDB.lastError().text()));
    //QFile::remove(fileName);//不能 成功打开删除 数据库
   }
    SqliteDB.removeDatabase(fileName);
    qDebug() << "sqlite connected";
    CreateConversation();
}



void SqliteConnect:: CreateConversation()
{
    if (QSqlDatabase::database().tables().contains("Conversations")) {
        // The table already exists; we don't need to do anything.
        return;
    }

    QSqlQuery query;
    if (!query.exec(//基本信息： 发送方 接收方 时间戳 消息/外键
        "CREATE TABLE IF NOT EXISTS 'Conversations' ("
        "'author' INTEGER NOT NULL,"
        "'recipient' INTEGER NOT NULL,"
        "'timestamp' TEXT NOT NULL,"
        "'message' TEXT NOT NULL,"
        "FOREIGN KEY('author') REFERENCES Contacts ( name ),"
        "FOREIGN KEY('recipient') REFERENCES Contacts ( name )"
        ")")) {
        qFatal("Failed to query database: %s", qPrintable(query.lastError().text()));
    }

    query.exec("INSERT INTO Conversations VALUES('0', '2', '2016-01-07T14:36:06', 'Hello!')");
    query.exec("INSERT INTO Conversations VALUES('2', '0', '2016-01-07T14:36:16', 'Good afternoon.')");
}


void SqliteConnect:: InsertRecord(MsgFormat InsRecord)
{
    QSqlQuery query;
    QString QueryStr = QString("INSERT INTO Conversations VALUES('%1','%2','%3','%4')")
            .arg(InsRecord.SenderID)
            .arg(InsRecord.RecverID)
            .arg(InsRecord.MsgTime)
            .arg(InsRecord.MsgContent);
    query.exec(QueryStr);

}



QSqlQuery SqliteConnect :: GetRecord(int Id)
{
    QSqlQuery query(QString("SELECT * FROM Conversations WHERE recipient = '%1' OR author = '%1';").arg(Id));
    //qDebug() << QString("SELECT * FROM Conversation WHERE recipient = '%1' OR author = '%1'").arg(Id);
    return query ;
}









