#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <QWidget>
#include <QString>
#include <QTcpSocket>
#include <QString>
#include <cstring>
#include "msg.h"
namespace Ui {
class Conversation;
}

class Conversation : public QWidget
{
    Q_OBJECT

public:
     Conversation(QWidget *parent = nullptr,QString UserName = "",int UserId = 0, QTcpSocket *ContectRecTcp = nullptr);
    ~Conversation();
     void SetConversation(int);
signals:
     void SendMsg(MsgFormat);

private slots:
     void CReadText(MsgFormat);
     void on_pushButton_send_clicked();

private:
    Ui::Conversation *ui;
    QTcpSocket *mytcp ;
    int YourId; // 会话中对方的名字
    int MyId=0;   //会话中自己的名字
};

#endif // CONVERSATION_H
