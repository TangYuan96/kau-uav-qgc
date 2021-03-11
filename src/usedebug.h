#ifndef USEDEBUG_H
#define USEDEBUG_H

#include <QDebug>

#define debug1  // error  print
#ifdef debug1
    #define qDebug1(format,...)  qDebug("File:%s, Function:%s, Line:%d. Info:" format , __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define qDebug1(format,...)
#endif

#define debug2  // run state print
#ifdef debug2
    #define qDebug2(format,...)  qDebug("File:%s, Function:%s, Line:%d. Info:" format , __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define qDebug2(format,...)
#endif

//#define debug3  // value  print
#ifdef notest
    #define qDebug3(format,...)  qDebug("File:%s, Function:%s, Line:%d. Info:" format , __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define qDebug3(format,...)
#endif


#endif // USEDEBUG_H

