#ifndef MANAGER_H
#define MANAGER_H

class ConnectionController;
class Algorithm;
class Publisher;
class Adaptor;
class Synchronizer;
class AlgorithmQueue;

class Manager
{
public:
    Manager();

private:
    ConnectionController* connectionController;
    Algorithm *algorithm;
    Publisher *publisher;
    Adaptor *adaptor;
    Synchronizer *synchronizer;
    AlgorithmQueue *algQueue;
};

#endif // MANAGER_H
