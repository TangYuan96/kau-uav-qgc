#include "globalv.h"
#include "threadsafe_queue.h"
#include <QString>
#include "datareceive.h"
#include "statesendthread.h"
threadsafe_queue<QString> receiMsgQueue;
threadsafe_queue<QString> sendMsgQueue;


//DataReceive *m_dataReceive;

//globalV::globalV()
//{

//}


