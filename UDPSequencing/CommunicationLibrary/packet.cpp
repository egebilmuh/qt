#include "packet.h"

Packet::Packet()
    :id (0)
    ,sequence (0)
{
    std::fill(data, data+dataSize,0);
}
