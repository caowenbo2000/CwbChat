#include "tcpheartbeat.h"
#include <QDebug>
#include <QString>
//#include <windows.h>
Tcpheartbeat :: Tcpheartbeat(QObject *par) :QThread (par)
{

}

void Tcpheartbeat::run()
{
//    qDebug()<<"Fuck You";
//    //192.168.112.130 虚拟机
//    mytcp.connectToHost("127.0.0.1",8081);//连接服务器

//    //QString str = "Heartbeat";
//    char str = 'a';
//    mytcp.write(&str,1);
//    mytcp.write(&str,1);
//    mytcp.write(&str,1);
    int a = 1 ;
    qDebug() <<a ;
    while(1)
    {
        //mytcp->write(&str,1);
        //qDebug()<<"Fuck You";
        qDebug() << "fuck you" ;
        sleep(1);
    }
}
