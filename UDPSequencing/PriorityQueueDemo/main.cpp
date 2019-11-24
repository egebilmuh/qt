#include <QCoreApplication>
#include <queue>
#include <iostream>

using namespace std;

struct beam
{
    int packetNo;
    float data[1024];

    beam():packetNo(0){}

    friend bool operator < (const beam& lhs, const beam& rhs)
    {
        return lhs.packetNo < rhs.packetNo;
    }
    friend bool operator > (const beam& lhs, const beam& rhs)
    {
        return lhs.packetNo > rhs.packetNo;
    }
};

template<class T>
class MyCompare {
public:

  bool operator()( T a, T b) {
    return (a) > (b);
  }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::priority_queue<beam, std::vector<beam>, MyCompare<beam>> pq;

    beam b;
    b.packetNo = 10;
    b.data[0] = 100;
    pq.push(b);
    beam b1;
    b1.data[0] = 1000;
    b1.packetNo = 100;
    pq.push(b1);
    beam b2;
    b2.data[0] = 200;
    b2.packetNo = 20;
    pq.push(b2);
    beam b3;
    b3.data[0] = 500;
    b3.packetNo = 50;
    pq.push(b3);
    beam b4;
    b4.data[0] = 700;
    b4.packetNo = 70;
    pq.push(b4);
    beam b5;
    b5.data[0] = 400;
    b5.packetNo = 40;
    pq.push(b5);


    while (!pq.empty()) {
        cout << pq.top().data[0] << endl;
        pq.pop();
    }


    return a.exec();
}
