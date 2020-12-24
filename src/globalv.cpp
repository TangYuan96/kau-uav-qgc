#include "globalv.h"
#include "threadsafe_queue.h"
#include <QString>

threadsafe_queue<QString> receiMsgQueue;
threadsafe_queue<QString> sendMsgQueue;

DataReceive *m_dataReceive;

//globalV::globalV()
//{

//}


