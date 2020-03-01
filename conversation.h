#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <QWidget>
#include <QString>
#include <QTcpSocket>
#include <QString>
#include <cstring>

namespace Ui {
class Conversation;
}

class Conversation : public QWidget
{
    Q_OBJECT

public:
     Conversation(QWidget *parent = nullptr,QString UserName = "",int UserId = 0 );
    ~Conversation();
     void SetConversation(int);

private slots:
     void CReadText();
     void on_pushButton_send_clicked();

private:
    Ui::Conversation *ui;
    QTcpSocket *mytcp = new QTcpSocket();
};

#endif // CONVERSATION_H
