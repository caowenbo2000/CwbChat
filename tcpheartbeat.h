#ifndef TCPHEARTBEAT_H
#define TCPHEARTBEAT_H

#include <QThread>
#include <QTcpSocket>

class Tcpheartbeat : public QThread
{
public:
    Tcpheartbeat(QObject *parent = nullptr);
    void run();
private:

};

#endif // TCPHEARTBEAT_H
