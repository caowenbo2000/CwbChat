#ifndef TCPHEARTBEAT_H
#define TCPHEARTBEAT_H

#include <QObject>
#include <QTcpSocket>

class TcpHeartBeat : public QObject
{
    Q_OBJECT
public:
    explicit TcpHeartBeat(QObject *parent = nullptr);
signals:

public slots:
    void HeartBeatRun();
};

#endif // TCPHEARTBEAT_H
