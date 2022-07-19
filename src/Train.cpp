#include <iostream>
#include <thread>
#include "Train.h"

Train::Train(std::string& inTag, Station* inTarget, float inArrivalTime) {
    tag = inTag;
    target = inTarget;
    arrivalTime = inArrivalTime;
}

void Train::depart() {
    std::cout << "Train " << tag << " departs to station." << std::endl;
    while (arrivalTime > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --arrivalTime;
    }

    std::cout << "Train " << tag << " approaches station." << std::endl;
    target->acceptTrain(this);
}
