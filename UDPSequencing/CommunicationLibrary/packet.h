#ifndef PACKET_H
#define PACKET_H

#include <QObject>
#include <iostream>
#include <QDataStream>
#include <math.h>
#include <queue>
#include "communicationlibrary_global.h"
#include <QDebug>
#include <cstring>

class Packet
{
        friend bool operator < (const Packet& lhs, const Packet& rhs)
        {
            if(lhs.sequence != rhs.sequence)
            {
                if((lhs.sequence < rhs.sequence && rhs.sequence - lhs.sequence < pow(2, serialbits-1))
                    || (lhs.sequence > rhs.sequence && lhs.sequence - rhs.sequence > pow(2, serialbits-1)))
                    return true;
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }


        friend bool operator > (const Packet& lhs, const Packet& rhs)
        {
            if(lhs.sequence != rhs.sequence)
            {
                if((lhs.sequence < rhs.sequence && rhs.sequence - lhs.sequence > pow(2, serialbits-1))
                        || (lhs.sequence > rhs.sequence && lhs.sequence - rhs.sequence < pow(2, serialbits-1)))
                    return true;
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

    friend bool operator == (const Packet& lhs, const Packet& rhs)
    {
        return lhs.sequence == rhs.sequence;
    }

    friend std::ostream &operator<<( std::ostream &output, const Packet &p ) {
        output << "id : " << p.id << " seq: " << p.sequence << " data: " << p.data[0];
        return output;
    }

    friend QDebug operator<<(QDebug debug, const Packet &p){
        QDebugStateSaver saver(debug);
        debug << "id : " << p.id << " seq: " << p.sequence << " data: " << p.data[0];
        return debug;
    }


    friend QDataStream &operator<<( QDataStream &output, const Packet &p ) {
        output << p.id;// << " seq: " << p.sequence << " data: " << p.data[0];
        output << p.sequence;

        for (int i = 0 ;i < dataSize; ++i) {
            output << p.data[i];
        }
        return output;
    }

    friend QDataStream &operator>>( QDataStream &output, Packet &p ) {
        output >> p.id;// << " seq: " << p.sequence << " data: " << p.data[0];
        output >> p.sequence;

        for (int i = 0 ;i < dataSize; ++i) {
            output >> p.data[i];
        }
        return output;
    }


public:
    Packet()    :id (0)
      ,sequence (0)
  {
      std::fill(data, data+dataSize,0.0f);
  }
    //Packet(const Packet &p);
    Packet& operator=(const Packet p)
    {
        std::cout << "packet assignment" << std::endl;
        this->id = p.id;
        this->sequence = p.sequence;
        std::memcpy(data, p.data, dataSize*sizeof(float));

        return *this;
    }
    int id;
    uint sequence;
    float data[dataSize];

//    bool operator < (Packet& rhs)
//    {
//        if(sequence != rhs.sequence)
//        {
//            if((sequence < rhs.sequence && rhs.sequence - sequence < pow(2, serialbits-1))
//                    || (sequence > rhs.sequence && sequence - rhs.sequence > pow(2, serialbits-1)))
//                return true;
//            else {
//                return false;
//            }
//        }
//        else {
//            return false;
//        }
//    }

//    bool operator > (Packet& rhs)
//    {
//        if(sequence != rhs.sequence)
//        {
//            if((sequence < rhs.sequence && rhs.sequence - sequence > pow(2, serialbits-1))
//                    || (sequence > rhs.sequence && sequence - rhs.sequence < pow(2, serialbits-1)))
//                return true;
//            else {
//                return false;
//            }
//        }
//        else {
//            return false;
//        }
//    }
};

Q_DECLARE_METATYPE(Packet);

#endif // PACKET_H
