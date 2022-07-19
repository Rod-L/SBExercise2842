#include <iostream>
#include <thread>

#include "Train.h"
#include "Station.h"

int main() {
    std::cout << "Enter arrival time of trains A, B and C (in seconds):" << std::endl;
    float atA, atB, atC;
    std::cin >> atA >> atB >> atC;
    std::cin.ignore(INT32_MAX, '\n');

    auto station = new Station;

    std::string tagA = "A", tagB = "B", tagC = "C";
    auto trainA = new Train(tagA, station, atA);
    auto trainB = new Train(tagB, station, atB);
    auto trainC = new Train(tagC, station, atC);

    std::thread wayA(&Train::depart, trainA);
    std::thread wayB(&Train::depart, trainB);
    std::thread wayC(&Train::depart, trainC);

    wayA.detach();
    wayB.detach();
    wayC.detach();

    std::cout << "All trains are departed. Enter 'depart' to let current train at station leave "
                 "or 'exit' to terminate program." << std::endl;
    while (station->trainsPassed < 3) {
        std::string command;
        std::cin >> command;
        if (command == "depart") {
            station->departTrain();
        } else if (command == "exit") {
            break;
        }
    }

    delete station;
    delete trainA;
    delete trainB;
    delete trainC;
}
