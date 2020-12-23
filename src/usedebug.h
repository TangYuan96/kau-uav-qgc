#ifndef USEDEBUG_H
#define USEDEBUG_H

#include <QDebug>

#define debug1  // error  print
#ifdef debug1
    #define qdebug1(format,...) qDebug("Error !!! File:%s, Function:%s, Line:%d. Info:" format , __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define qdebug1(format,...)
#endif

#define debug2  // run state print
#ifdef debug2
    #define qdebug2(format,...) qDebug("Run state . File:%s, Function:%s, Line:%d. Info:" format , __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define qdebug2(format,...)
#endif

#define debug3  // value  print
#ifdef debug3
    #define qdebug3(format,...) qDebug("Value .File:%s, Function:%s, Line:%d. Info:" format , __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
    #define qdebug3(format,...)
#endif


#endif // USEDEBUG_H
