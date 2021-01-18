#include "statesendthread.h"
#include "globalv.h"
#include <QDebug>
#include <QThread>
#include <string>
#include "datareceive.h"


stateSendThread::stateSendThread(QObject *parent) : QThread(parent)
{
  qDebug()<<"stateSendThread:"<<QThread::currentThreadId();
}




void stateSendThread::run()
{
    QString needSendMsg;

    QThread::sleep(2);

    // check the state of network
//    while(!m_dataReceive->connectStatus)
//    {
//        qDebug()<<"disconnect network";
//        QThread::sleep(1);
//    }

    while(1)
    {
//        if (!sendMsgQueue.is_empty())
//        {
//            while((!sendMsgQueue.is_empty()) && m_dataReceive->connectStatus)
//            {
//                sendMsgQueue.pop(needSendMsg);
//                // use the signals and slot ,use the datareceive class to  send the info
//                emit sendMsg(needSendMsg);
//                //m_dataReceive->dataRecvWS->sendTextMessage("needSendMsg");
//                qDebug()<<"send msg:"<<needSendMsg ;
//            }


//        }
//        else
        {// there is no msg to send
            qDebug()<<"no msg need to be send";
            QThread::sleep(1);
        }

    }

    exec();

}
