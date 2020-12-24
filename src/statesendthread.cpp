#include "statesendthread.h"
#include "globalv.h"
#include <QDebug>
#include <QThread>
#include <string>


stateSendThread::stateSendThread(QObject *parent) : QThread(parent)
{
  qDebug()<<"stateSendThread:"<<QThread::currentThreadId();
}


void stateSendThread::run()
{
    QString needSendMsg;

    // check the state of network
    while(!m_dataReceive->connectStatus)
    {
        qDebug()<<"disconnect network";
        QThread::sleep(1);
    }

    while(1)
    {
        if (!sendMsgQueue.is_empty())
        {
            while((!sendMsgQueue.is_empty()) && m_dataReceive->connectStatus)
            {
                sendMsgQueue.pop(needSendMsg);
                m_dataReceive->dataRecvWS->sendTextMessage(needSendMsg);
                qDebug()<<"send msg:"<<needSendMsg ;
            }


        }
        else
        {// there is no msg to send
            qDebug()<<"no msg need to be send";
            QThread::sleep(1);
        }

    }

    exec();

}
