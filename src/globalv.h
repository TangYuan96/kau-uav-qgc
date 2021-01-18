#ifndef GLOBALV_H
#define GLOBALV_H

#include "threadsafe_queue.h"
#include <QString>
#include "datareceive.h"

#include <fstream>
#include <iomanip>
#include "json.hpp"

extern threadsafe_queue<QString> receiMsgQueue;
extern threadsafe_queue<QString> sendMsgQueue;



using namespace std;
using json = nlohmann::json;

// value about websocket
//extern DataReceive *m_dataReceive;
//extern stateSendThread stateSendT;


//class globalV
//{
//public:
//    globalV();
//};

#endif // GLOBALV_H
