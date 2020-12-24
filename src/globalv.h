#ifndef GLOBALV_H
#define GLOBALV_H

#include "threadsafe_queue.h"
#include <QString>
#include "datareceive.h"

extern threadsafe_queue<QString> receiMsgQueue;
extern threadsafe_queue<QString> sendMsgQueue;

// value about websocket
extern DataReceive *m_dataReceive;



//class globalV
//{
//public:
//    globalV();
//};

#endif // GLOBALV_H
