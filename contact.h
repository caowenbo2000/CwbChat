#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QThread>
#include <QTcpSocket>
#include "tcpheartbeat.h"
#include "msg.h"
namespace Ui {
class Contact;
}

class Contact : public QWidget
{
    Q_OBJECT

public:
    explicit Contact(QWidget *parent = nullptr);
    ~Contact();
    void test();
    void TcpConfig(); //配置tcp连接

signals:
  void startRunning(); // 用于触发新线程中的耗时操作函数
  void RecNewMsg(MsgFormat);

public slots:
    void prin(QString CurrentSelectText);
    void Switch(QString UserName);
    void SaveMsg();
    void SendtoServer(MsgFormat);
private:
    Ui::Contact *ui;
    TcpHeartBeat *mythread;
    QThread *Thread;
    QTcpSocket *ContactRecTcp;
};

#endif // CONTACT_H
