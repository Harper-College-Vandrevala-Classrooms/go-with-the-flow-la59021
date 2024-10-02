#include <iostream>
#include <cmath>
#include "Object.hpp"
using namespace std;

#define TIME_STEP = 1
Object::Object() {
}

void Object::setObject(vector<double> Stats, vector<bool> sourceOrSink, vector<double> Temps) {
    rodStats = Stats; // inital temp, rod length, K
    currentRod.resize(rodStats[1]); // current temps
    nextRod.resize(rodStats[1]); // next temps
    constants = sourceOrSink; // is source or sink (held constant)
    constantTemps = Temps; // temps constants are held at
    // fill currentRod
    for (int x = 0; x < currentRod.size(); x++) {
        if (constants[x]){
            currentRod[x] = constantTemps[x];
        }
        else {
            currentRod[x] = rodStats[0];
        }
    }

    // fill nextRod
    for (int x = 0; x < currentRod.size(); x++) {
        if (constants[x]){
            nextRod[x] = constantTemps[x];
        }
        else {
            nextRod[x] = rodStats[0];
        }
    }

}

void Object::tick() {
    for (int x = 0; x < currentRod.size(); x++) {
        if (!constants[x]) {
            double current = currentRod[x];
            double next = current; // = current - K(currentRight - 2current + currentLeft)
            double loss;
            if (x == 0) {
                loss = rodStats[2]*(currentRod[x+1] - 2*current + currentRod[x]);
            }
            else if (x == currentRod.size()-1) {
                loss = rodStats[2]*(current - 2*current + currentRod[x-1]);
            }
            else{
                loss = rodStats[2]*(currentRod[x+1] - 2*current + currentRod[x-1]);
            }
            next += loss;
            nextRod[x] = next;
        }
        else {
            nextRod[x] = currentRod[x];
        }
    }
    for (int y = 0; y < rodStats[1]; y++) {
        currentRod[y] = nextRod[y];
    }
}

void Object::pretty_print() {
//    for (int y = 0; y < currentRod.size(); y++) {
//        cout << currentRod[y] << ", ";
//    }
    string row1;
    string row2;
    string row3;
    for (int x = 0; x < rodStats[1]; x++) {
        string tempString = to_string(currentRod[x]);
        tempString.resize(6);
        row1 += "+----------";
        row2 += "|  " + tempString + "  ";
        row3 += "+----------";
    }
    row1 += "+";
    row2 += "|";
    row3 += "+";
    cout << row1 << endl << row2 << endl << row3 << endl;
}

vector<double> Object::getCurrentRod() {
    return currentRod;
}
