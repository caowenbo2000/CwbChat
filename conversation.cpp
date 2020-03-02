#include "conversation.h"
#include "ui_conversation.h"
#include "msg.h"
#include "sqliteconnect.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include <ctime>
#include <sstream>
#include <cstring>

Conversation::Conversation(QWidget *parent,QString UserName , int UserId ,QTcpSocket * ContectRecTcp) :
    QWidget(parent),
    ui(new Ui::Conversation)
{
    YourId = UserId ;
    mytcp = ContectRecTcp;
    //虚拟机:192.168.112.130
    this->setWindowFlag(Qt::Window);//子窗口独立显示
    ui->setupUi(this);
    ui->label->setText(QString("%1").arg(YourId));
    ui->textEdit_read->setReadOnly(1);
    this->SetConversation(UserId);
    connect(parent , SIGNAL(RecNewMsg(MsgFormat)), this, SLOT(CReadText(MsgFormat) ));  //拉取收到的信息
    connect(this , SIGNAL(SendMsg(MsgFormat)), parent , SLOT(SendtoServer(MsgFormat)));
}
Conversation::~Conversation()
{
    delete ui;
}


void Conversation::on_pushButton_send_clicked()//发送消息 拉取消息 发送
{   //构建消息结构体类型 发送 存进数据库
    QByteArray CurrentText= ui->textEdit_write->toPlainText().toUtf8();

    MsgFormat CurrentMsg;
    CurrentMsg.SenderID=MyId ;
    CurrentMsg.RecverID=YourId;

    std::stringstream strtime; //拉取当前时间 组包
    std::time_t currenttime = std::time(0);
    char tAll[20];
    std::strftime(tAll, sizeof(tAll), "%Y-%m-%dT%H:%M:%S", std::localtime(&currenttime));  //2016-01-07T14:36:16
    memcpy(CurrentMsg.MsgTime,tAll,20);

    char *temp;//转换成char
    temp=CurrentText.data();
    memcpy(CurrentMsg.MsgContent,temp,256);
    SqliteConnect::InsertRecord(CurrentMsg);
    emit(SendMsg(CurrentMsg));
    ui->textEdit_write->clear();
    //界面加上
    ui->textEdit_read->append(QString("[%1]{%2}:").arg(CurrentMsg.SenderID).arg(CurrentMsg.MsgTime));
    ui->textEdit_read->append(CurrentMsg.MsgContent);
}

void Conversation::CReadText(MsgFormat RecMsg)
{
    if(YourId != RecMsg.SenderID ) return ;
    ui->textEdit_read->append(QString("[%1]{%2}:").arg(RecMsg.SenderID).arg(RecMsg.MsgTime));
    ui->textEdit_read->append(RecMsg.MsgContent);
}

void Conversation::SetConversation(int Id)
{
    QSqlQuery CurrentQuery = SqliteConnect::GetRecord(Id) ;
    while(CurrentQuery.next())
    {
        QString sender = CurrentQuery.value(0).toString();
        QString SendTime = CurrentQuery.value(2).toString();
        QString Sendertext = QString("[%1]{%2}:").arg(sender).arg(SendTime);
        QString val = CurrentQuery.value(3).toString();
        ui->textEdit_read->append(Sendertext);
        ui->textEdit_read->append(val);
    }
}
