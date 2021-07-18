#include "saasimmitator.h"
#include <QDataStream>
#include <unistd.h>

SaaSImmitator::SaaSImmitator()
{

}

SaaSImmitator::~SaaSImmitator()
{

}

void SaaSImmitator::startServer()
{
    if (this->listen(QHostAddress::Any,1919)){
        qDebug()<<"Server listening network";
    }
    else {
        qDebug()<<"Server NOT listening network";
    }
}

void SaaSImmitator::incomingConnection(qintptr socketDescriptor)
{
    m_psocket = new QTcpSocket(this);
    m_psocket->setSocketDescriptor(socketDescriptor);

    connect(m_psocket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(m_psocket,SIGNAL(disconnected()),this,SLOT(sockDisconected()));

    qDebug()<<endl<<"IoT connected.";
    //m_psocket->write("Server is active");
}

void SaaSImmitator::sockReady()
{
    if(m_psocket->waitForConnected(500)){
        m_psocket->waitForReadyRead(500);
        m_Data = m_psocket->readAll();

        QDataStream out(&m_Data,QIODevice::ReadOnly);
        ThingData TD;
        TD.id = m_psocket->socketDescriptor();
        out >> TD.ip
            >> TD.latitude
            >> TD.lontitude;

        int index = 0;
        foreach (ThingData varTD, m_Things) {
            if (varTD.ip == TD.ip){
                m_Things.remove(index);
            }
            ++index;
        }

        if (m_Things.count()>10){
            m_Things.erase(m_Things.begin());
        }

        m_Things.append(TD);

        qDebug()<<"SAAS ReadyRead client: "    << TD.id;
        qDebug()<<"SAAS ReadyRead ip: "        << TD.ip;
        qDebug()<<"SAAS ReadyRead latitude: "  << TD.latitude;
        qDebug()<<"SAAS ReadyRead lontitude: " << TD.lontitude;

        //ОТВЕТ ========================================>
        m_psocket->connectToHost(TD.ip, 1919);
        QByteArray buffer;
        qDebug()<<"===========================";
        foreach (ThingData oneTD, m_Things) {
            qDebug()<<"SAAS Send client: "    << oneTD.id;
            qDebug()<<"SAAS Send ip: "        << oneTD.ip;
            qDebug()<<"SAAS Send latitude: "  << oneTD.latitude;
            qDebug()<<"SAAS Send lontitude: " << oneTD.lontitude <<endl;


            QDataStream in(&buffer, QIODevice::WriteOnly);
            in << (quint16)0
               << oneTD.id
               << oneTD.ip
               << oneTD.latitude
               << oneTD.lontitude;
            in.device()->seek(0);
            in << (quint16)(buffer.size()-sizeof (quint16));
            m_psocket->write(buffer);
            m_psocket->waitForBytesWritten();
        }
    }
}

void SaaSImmitator::sockDisconected()
{
    qDebug()<<"Client disconnect";
    m_psocket->deleteLater();
}


