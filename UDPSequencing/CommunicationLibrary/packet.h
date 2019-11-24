#ifndef PACKET_H
#define PACKET_H

#include <QObject>
#include <iostream>
#include <QDataStream>

const int dataSize = 6144;

class Packet
{

    friend bool operator < (const Packet& lhs, const Packet& rhs)
    {
        return lhs.sequence < rhs.sequence;
    }
    friend bool operator > (const Packet& lhs, const Packet& rhs)
    {
        return lhs.sequence > rhs.sequence;
    }

    friend std::ostream &operator<<( std::ostream &output, const Packet &p ) {
             output << "id : " << p.id << " seq: " << p.sequence << " data: " << p.data[0];
             return output;
    }

    friend QDataStream &operator<<( QDataStream &output, const Packet &p ) {
             output << p.id;// << " seq: " << p.sequence << " data: " << p.data[0];
             output << p.sequence;

             for (int i = 0 ;i < dataSize; ++i) {
                 output << p.data[i];
             }
             return output;
    }

public:
    Packet();
    int id;
    uint sequence;
    float data[dataSize];
};

Q_DECLARE_METATYPE(Packet);

#endif // PACKET_H
