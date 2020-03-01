#include "contact.h"
#include "ui_contact.h"
#include "conversation.h"
#include "sqliteconnect.h"
Contact::Contact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contact)
{
    SqliteConnect();                  //连接数据库 创建表
    this->setStyleSheet("background-color:#F5A6D9;");
    ui->setupUi(this);
   // this->setWindowFlag(Qt::Desktop);
    test();//暂时假装拉取联系人
    //qDebug() <<QThread::currentThreadId();当前线程
    mythread = new TcpHeartBeat();
    Thread = new QThread(this);
    mythread->moveToThread(Thread);
    Thread->start();
    //mythread->HeartBeatRun();
    connect(this,SIGNAL(startRunning()), mythread , SLOT(HeartBeatRun()) );
    connect(ui->listWidget
            , SIGNAL(currentTextChanged(QString)),
                               this,  SLOT(prin(QString)));
    connect(ui->listWidget
            , SIGNAL(currentTextChanged(QString)),
                               this,  SLOT(Switch(QString)));
    emit startRunning();
}

Contact::~Contact()
{
    delete mythread;
    delete ui;
}

void Contact::test()
{
    for(int i=1;i<50;i++)
    {
        ui->listWidget->addItem(new QListWidgetItem(QIcon("D:/qtdebug/CwbChat/img/qq.png"), tr("%1").arg(i)));
    }
}

void Contact::prin(QString CurrentSelectText)
{
    qDebug() << CurrentSelectText ;
}

void Contact::Switch(QString UserName)
{
    if(UserName!="1")
    {
    Conversation*Aconversation = new Conversation(this,UserName,2);
    Aconversation->show();
    }
}
