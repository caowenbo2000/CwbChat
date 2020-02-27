#include "conversation.h"
#include "ui_conversation.h"

Conversation::Conversation(QWidget *parent,QString UserName , int UserId) :
    QWidget(parent),
    ui(new Ui::Conversation)
{
    mytcp->connectToHost("localhost",8888);//连接服务器
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
    mytcp->write(CurrentText);
    ui->textEdit_write->clear();
}


void Conversation::CReadText()
{
    char CReceiveData[200];
    mytcp->read(CReceiveData,200);
    ui->textEdit_read->append(CReceiveData);
}
