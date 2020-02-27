#include "conversation.h"
#include "ui_conversation.h"
#include "msg_test.h"

Conversation::Conversation(QWidget *parent,QString UserName , int UserId) :
    QWidget(parent),
    ui(new Ui::Conversation)
{
    //虚拟机:192.168.112.130
    mytcp->connectToHost("192.168.112.130",8080);//连接服务器
    this->setWindowFlag(Qt::Window);//子窗口独立显示
    ui->setupUi(this);
    ui->label->setText(UserName);
    ui->textEdit_read->setReadOnly(1);
    connect(mytcp, &QIODevice::readyRead, this, &Conversation::CReadText);
}
Conversation::~Conversation()
{
    mytcp->close();
    delete ui;
}


void Conversation::on_pushButton_send_clicked()//发送消息 拉取消息 发送
{
    QByteArray CurrentText= ui->textEdit_write->toPlainText().toUtf8();

    MsgFormat CurrentMsg;
    CurrentMsg.SenderID=1,CurrentMsg.RecverID=2,CurrentMsg.SendTime=3;
    char *temp;//转换成char
    temp=CurrentText.data();
    memcpy(CurrentMsg.MsgContent,temp,256);
    char buffer[268];
    memcpy(buffer,&CurrentMsg,268);
    mytcp->write(buffer,268);
    ui->textEdit_write->clear();

}


void Conversation::CReadText()
{
    char CReceiveData[200];
    mytcp->read(CReceiveData,200);
    ui->textEdit_read->append(CReceiveData);
}
