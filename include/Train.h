#pragma once

#include <string>
#include "Station.h"

class Train{
    float arrivalTime; // seconds
    Station* target;

public:
    std::string tag;

    Train(std::string& inTag, Station* inTarget, float inArrivalTime);
    void depart();
};