#ifndef SAASIMMITATOR_H
#define SAASIMMITATOR_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QString>

struct ThingData{
    int id          ;
    QString ip      ;
    float latitude  ;
    float lontitude ;
};

class SaaSImmitator : public QTcpServer
{
    Q_OBJECT
public:
    SaaSImmitator();
    ~SaaSImmitator();

    QTcpSocket* m_psocket;
    QByteArray m_Data;

public slots:
    void startServer();
    void incomingConnection(qintptr socketDescriptor);
    void sockReady();
    void sockDisconected();

private:
    QVector<ThingData> m_Things; //данные по входящим iot
};

#endif // SAASIMMITATOR_H
