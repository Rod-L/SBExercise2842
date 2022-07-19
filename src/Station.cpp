#include <iostream>
#include "Train.h"
#include "Station.h"

Station::Station() {
    trainsPassed = 0;
    trainAtStation = nullptr;
}

void Station::acceptTrain(Train* train) {
    if (train == nullptr) return;

    stationAccess.lock();
    trainAtStation = train;
    std::cout << train->tag << " arrives at station." << std::endl;
}

void Station::departTrain() {
    if (trainAtStation == nullptr) {
        std::cout << "Station is empty, no trains to depart." << std::endl;
        return;
    }

    ++trainsPassed;
    stationAccess.unlock();
    std::cout << trainAtStation->tag << " departs from station." << std::endl;
}