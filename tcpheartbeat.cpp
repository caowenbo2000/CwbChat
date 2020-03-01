#include "tcpheartbeat.h"
#include <windows.h>
#include<QThread>

TcpHeartBeat::TcpHeartBeat(QObject *parent) : QObject(parent)
{

}


void TcpHeartBeat::HeartBeatRun()
{
    qDebug() << "Start to HeartBeat 1";
    //qDebug() <<QThread::currentThreadId();
    QTcpSocket * HeartBeatSocket;
    HeartBeatSocket = new QTcpSocket ;
    //192.168.112.130 虚拟机
    HeartBeatSocket->connectToHost("192.168.112.130",8080);//连接服务器
    if(HeartBeatSocket -> waitForConnected()==0)
    {
        qDebug() <<"Sorry that you cant connect to server";
        qDebug() << HeartBeatSocket->errorString();
        return ;
    }
    qDebug() << "Start to HeartBeat ";
    QString str = "Heartbeat";
    int TempTime=0;
    while(1)
    {
       HeartBeatSocket->write(str.toUtf8().data());
        HeartBeatSocket->flush();
        //qDebug()<<TempTime;
        TempTime++;
        QThread::sleep(1);
    }
}
