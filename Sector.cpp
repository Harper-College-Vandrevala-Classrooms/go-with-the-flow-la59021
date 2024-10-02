#include "Sector.hpp"

Sector::Sector(int initalType, double initalTemp) {
    type = initalType;
    temp = initalTemp;
}

void Sector::setTemp(double newTemp) {
    temp = newTemp;
}

double Sector::getTemp() {
    return temp;
}

int Sector:: getType() {
    return type;
}
