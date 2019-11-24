#ifndef COMMUNICATIONLIBRARY_GLOBAL_H
#define COMMUNICATIONLIBRARY_GLOBAL_H


#include <QtCore/qglobal.h>
#include <iostream>
#include <math.h>
#include <QFile>
#include <QDebug>


#if defined(COMMUNICATIONLIBRARY_LIBRARY)
#  define COMMUNICATIONLIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COMMUNICATIONLIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif
const int dataSize = 3072;
const int serialbits = 8;

inline  quint64 powerOf2 (quint64 exponent)
{
    return quint64(1) << exponent;
}

inline bool isEquealOrGreater(uint num1, uint num2)
{
    if(num1 == num2)
        return true;
    else {
        if((num1 < num2 && num2 - num1 > pow(2, serialbits-1))
                || (num1 > num2 && num1 - num2 < pow(2, serialbits-1)))
        {
            qDebug() << "**************greater. Expected: " << num2 << " incoming: " << num1 ;
            return true;
        }
        else {
            return false;
        }
    }
}

inline bool isGreater(uint num1, uint num2)
{
    if((num1 < num2 && num2 - num1 > pow(2, serialbits-1))
            || (num1 > num2 && num1 - num2 < pow(2, serialbits-1)))
        return true;
    else {
        return false;
    }
}
inline bool isEqual(uint num1, uint num2)
{
    if (num1 == num2)
        return true;
    return  false;
}
inline bool isSmaller(uint num1, uint num2)
{
    if((num1 < num2 && num2 - num1 < pow(2, serialbits-1))
            || (num1 > num2 && num1 - num2 > pow(2, serialbits-1)))
        return true;
    else {
        return false;
    }
}

struct floatData
{
    float data[dataSize*3];
};

#endif // COMMUNICATIONLIBRARY_GLOBAL_H
