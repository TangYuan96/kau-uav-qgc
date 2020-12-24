#include "orderexethread.h"
#include "globalv.h"

orderExeThread::orderExeThread(QObject *parent) : QThread(parent)
{
  qDebug()<<"orderExeThread:"<<QThread::currentThreadId();
}


void handleOrder(QString orderMsg)
{
    // String to json


    // get order id  from json ,
    // and goto special process function with the id



}



void orderExeThread::run()
{
   QString orderMsg;

   while(1)
   {
       //have msg
       if (!receiMsgQueue.is_empty())
       {
           while(!receiMsgQueue.is_empty())
           {// not empty,and read the order

                receiMsgQueue.pop(orderMsg);
                qDebug()<<"receive msg:"<<orderMsg;
                handleOrder(orderMsg);
           }
       }
       else //no msg ,and sleep
       {
            qDebug()<<"no receive msg";
            QThread::sleep(1);
       }
   }

   exec();

}
