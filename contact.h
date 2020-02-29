#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QThread>
#include "tcpheartbeat.h"

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

signals:
  void startRunning(); // 用于触发新线程中的耗时操作函数

public slots:
    void prin(QString CurrentSelectText);
    void Switch(QString UserName);
private:
    Ui::Contact *ui;
    TcpHeartBeat *mythread;
    QThread *Thread;
};

#endif // CONTACT_H
