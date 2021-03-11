#include "datareceive.h"
#include <QDebug>
#include <QWebSocket>
#include "globalv.h"
#include "statesendthread.h"
#include <usedebug.h>

DataReceive::DataReceive(QObject *parent):QObject(parent)
{
    dataRecvWS = Q_NULLPTR;
    connectStatus = false;
    m_timer = new QTimer();
    m_timerFSend = new QTimer(); // set time to send the mesg
    m_timerFSend->start(3000);
    myurl = "ws://222.20.75.16:8443/v1" ;

}

DataReceive::~DataReceive(){

}

/**
 * @breaf 创建WebSocket连接
 */
void DataReceive::createDataRecvWS(){
    qDebug2("start!!!");

    if(dataRecvWS == Q_NULLPTR){
        qDebug2("create websocket!");
        dataRecvWS = new QWebSocket();
        connect(dataRecvWS, &QWebSocket::disconnected, this, &DataReceive::onDisConnected, Qt::AutoConnection);
        connect(dataRecvWS, &QWebSocket::textMessageReceived, this, &DataReceive::onTextReceived, Qt::AutoConnection);
        connect(dataRecvWS, &QWebSocket::connected, this, &DataReceive::onConnected, Qt::AutoConnection);
        connect(m_timer, &QTimer::timeout, this, &DataReceive::reconnect, Qt::AutoConnection);
        connect(m_timerFSend, &QTimer::timeout, this, &DataReceive::sendmesg, Qt::AutoConnection);

        //connect(stateSendT, SIGNAL(&stateSendThread::sendMsg(QString)), this, SLOT(&DataReceive::sendmesg(QString)), Qt::DirectConnection);
        //connect(stateSendT, &stateSendThread::sendMsg,this, &DataReceive::sendmesg, Qt::QueuedConnection);

        dataRecvWS->open(QUrl(myurl));
    }


}

/**
 * @breaf 判断连接状态
 * @note  当连接成功后，触发该函数
 */
void DataReceive::onConnected(){
    qDebug2("DataReveive websocket is already connect! ");
    connectStatus = true;
    m_timer->stop();
    qDebug()<<"Address：%s"<<dataRecvWS->peerAddress();
}

/**
 * @breaf 数据处理函数
 * @param msg，数据信息
 * @note  当收到服务端发送的数据时，触发该函数
 */
void DataReceive::onTextReceived(QString msg){

    dataRecvWS->sendTextMessage(msg);
    // store the msg from S,and waite the order thread to do
    receiMsgQueue.push(msg);

}

/**
 * @breaf send mesg
 * @param msg，数据信息
 * @note  get the msg,and send to server
 */
void DataReceive::sendmesg(){

    QString needSendMsg;

    m_timerFSend->stop();

    if  ( connectStatus = true)
    {

        if (!sendMsgQueue.is_empty())
        {
            while(!sendMsgQueue.is_empty())
            {
                sendMsgQueue.pop(needSendMsg);
                dataRecvWS->sendTextMessage(needSendMsg);
            }

        }
    }



    // set next time for send
    if  ( connectStatus = false)
    {
        m_timerFSend->start(3000);
    }
    else
    {
         m_timerFSend->start(500);
    }

}


/**
 * @breaf 连接断开
 * @note  当连接断开时，触发该函数
 */
void DataReceive::onDisConnected(){
    qDebug2("DataReceive websocket is disconnected!!!");
    connectStatus = false;
    m_timer->start(3000);/*-<当连接失败时，触发重连计时器，设置计数周期为3秒 */
}

/**
 * @breaf 周期重连函数
 * @note  连接建立成功时，调用该函数
 */
void DataReceive::reconnect(){
    qDebug2("try to reconnect!");
    dataRecvWS->abort();
    dataRecvWS->open(QUrl(myurl));
}
