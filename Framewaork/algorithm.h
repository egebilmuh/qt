#ifndef ALGORITHM_H
#define ALGORITHM_H

class AlgorithmQueue;

class Algorithm
{
public:
    Algorithm();
    void runModel();
private:
    AlgorithmQueue* algQueue;
};

#endif // ALGORITHM_H
