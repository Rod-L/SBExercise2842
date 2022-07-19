#pragma once

#include <mutex>

class Train;

class Station{
    std::mutex stationAccess;
    Train* trainAtStation;

public:
    int trainsPassed;

    Station();

    void acceptTrain(Train* train);
    void departTrain();
};