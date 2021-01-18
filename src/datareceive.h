/**
 * @breaf 用于创建websocket连接
 * @note  该类实现了client端基本的websocket创建，自动重连。
 * @author  LittleMushroom
 * date   2018年5月15日
 */

#ifndef DATARECEIVE_H
#define DATARECEIVE_H

#include <QtCore/QObject>
#include <QWebSocket>
#include <QString>
#include <QTimer>
#include "statesendthread.h"

class DataReceive : public QObject
{
    Q_OBJECT
public:
    DataReceive(QObject *parent=0);
    ~DataReceive();
    bool connectStatus;
    QWebSocket *dataRecvWS;     /*-<websocket类 */

public slots:
    void createDataRecvWS();    /*-<创建websocket连接 */

private:

            /*-<websocket连接状态，连接成功：true；断开：false */
    void reconnect();           /*-<周期重连函数 */
    QTimer *m_timer;            /*-<周期重连Timer */
    //stateSendThread *stateSendT;/
    QTimer *m_timerFSend;            /*-<周期重连Timer */
    QString myurl  ;

private slots:
    void onConnected();                 /*-<socket建立成功后，触发该函数 */
    void onTextReceived(QString msg);   /*-<收到Sev端的数据时，触发该函数 */
    void sendmesg();
    void onDisConnected();              /*-<socket连接断开后，触发该函数 */
};

#endif // DATARECEIVE_H
