#include "contact.h"
#include "ui_contact.h"
#include "conversation.h"
#include "sqliteconnect.h"
#include <cstring>
Contact::Contact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contact)
{
    SqliteConnect();                  //连接数据库 创建表
    this->setStyleSheet("background-color:#F5A6D9;");
    ui->setupUi(this);
    test();//暂时假装拉取联系人
    TcpConfig();
    //qDebug() <<QThread::currentThreadId();当前线程
    mythread = new TcpHeartBeat();
    Thread = new QThread(this);
    mythread->moveToThread(Thread);
    Thread->start();
    //mythread->HeartBeatRun();
    connect(this,SIGNAL(startRunning()), mythread , SLOT(HeartBeatRun()) );
    connect(ui->listWidget
            , SIGNAL(currentTextChanged(QString)),
                               this,  SLOT(Switch(QString)));
    emit startRunning();
}

Contact::~Contact()
{
    delete Thread ;
    delete ContactRecTcp;
    delete mythread;
    delete ui;
}

void Contact::test() //拉取所有好友
{
    for(int i=1;i<50;i++)
    {
        ui->listWidget->addItem(new QListWidgetItem(QIcon("D:/qtdebug/CwbChat/img/qq.png"), tr("%1").arg(i)));
    }
}


void Contact::Switch(QString UserName)
{
    if(UserName!="1")
    {
        Conversation*Aconversation = new Conversation(this,UserName,UserName.toInt());
        Aconversation->show();
    }
}

void Contact::SaveMsg()
{
    char RecMsg[ByteNumber];
    MsgFormat InsMsg;
    ContactRecTcp->read(RecMsg,ByteNumber);
    memcpy(&InsMsg,RecMsg,ByteNumber);
    SqliteConnect::InsertRecord(InsMsg);
    emit(InsMsg);
}

void Contact::TcpConfig()
{
    ContactRecTcp = new QTcpSocket(); //建立新的Tcp连接 接受服务器消息
    //虚拟机:192.168.112.130
    ContactRecTcp->connectToHost("127.0.0.1",8080);
    connect(ContactRecTcp, &QIODevice::readyRead, this, &Contact::SaveMsg);
}

void Contact::SendtoServer(MsgFormat SendTheMsg)
{
    char buffer[ByteNumber];
    memcpy(buffer,&SendTheMsg,ByteNumber);
    ContactRecTcp->write(buffer,ByteNumber);
}
