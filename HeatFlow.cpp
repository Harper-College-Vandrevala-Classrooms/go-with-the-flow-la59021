#include <iostream>
#include "HeatFlow.hpp"
using namespace std;

HeatFlow::HeatFlow() {
    vector<double> rodStats = askForStats(); // inital temp, rod length, K
    int numOfConstants = askHowManyConstants();
    vector<bool> constants = askWhereTheConstantsAre(numOfConstants, rodStats[1]);
    vector<double> constantTemps = askWhatConstantTempsAre(numOfConstants, rodStats[1], constants);
    HeatFlow(rodStats, constants, constantTemps);
}

HeatFlow::HeatFlow(vector<double> stats, vector<bool> sourceOrSink, vector<double> constantTemps) {
    o.setObject(stats, sourceOrSink, constantTemps);
}

HeatFlow::HeatFlow(double initalTemp, int rodLength, double kConstant, vector<bool> sourceOrSink, vector<double> constantTemps) {
    vector<double> rodStats {initalTemp, rodLength, kConstant};
    HeatFlow(rodStats, sourceOrSink, constantTemps);
}

void HeatFlow::tick() {
    o.tick();
}

void HeatFlow::pretty_print() {
    o.pretty_print();
}

string HeatFlow::getCurrentTemps() {
    string temps;
    for (int x = 0; x < o.getCurrentRod().size(); x++) {
        string tempString = to_string(o.getCurrentRod()[x]);
        tempString.resize(6);
        temps += tempString + ", ";
    };
    temps.resize(temps.size()-2);
    return temps;
}

vector<double> HeatFlow::askForStats() {
    vector<double> stats; // inital temp, rod length, K
    // inital temp
    double temp;
    cout << "What will the inital temperture be?" << endl;
    cin >> temp;
    stats.insert(stats.begin(), temp);

    // Number of sections
    int sections;
    cout << "How many sections will there be?" << endl;
    cin >> sections;
    stats.insert(stats.begin() + 1, sections);

    // K constant
    double k;
    cout << "What will the K constant be?" << endl;
    cin >> k;
    stats.insert(stats.begin() + 2, k);

    return stats;
}

int HeatFlow::askHowManyConstants() {
    cout << "How many Constants will there be?" << endl;
    int q;
    cin >> q;
    return q;
}

vector<bool> HeatFlow::askWhereTheConstantsAre(int numOfConstants, int rodLength) {
    vector<bool> constants(rodLength);
    for (int y = 0; y < constants.size(); y++) {
        constants[y] = false;
    }
    int index = 0;
    for (int x = 0; x < numOfConstants; x++) {
        if (x == 0) {
            cout << "What is the index of the 1st source?" << endl;
            cin >> index;
        }
        else if (x == 1) {
            cout << "What is the index of the 2nd source?" << endl;
            cin >> index;
        }
        else if (x == 2) {
            cout << "What is the index of the 3rd source?" << endl;
            cin >> index;
        }
        else {
            cout << "What is the index of the " << x+1 << "th source?" << endl;
            cin >> index;
        }
        constants[index] = true;
    }
    return constants;
}

vector<double> HeatFlow::askWhatConstantTempsAre(int numOfConstants, int rodLength, vector<bool> constants) {
    vector<double> constantTemps(rodLength);
    vector<int> indexs;
    for (int y = constants.size(); y > -1; y--) {
        if (constants[y]) {
            indexs.push_back(y);
        }
    }
    int temp = 0;
    int index = 0;
    for (int x = 0; x < numOfConstants; x++) {
        if (x == 0) {
            cout << "What is the temp of the 1st constant?" << endl;
            cin >> temp;
        }
        else if (x == 1) {
            cout << "What is the temp of the 2nd constant?" << endl;
            cin >> temp;
        }
        else if (x == 2) {
            cout << "What is the temp of the 3rd constant?" << endl;
            cin >> temp;
        }
        else {
            cout << "What is the temp of the " << x+1 << "th constant?" << endl;
            cin >> temp;
        }
        constantTemps[indexs[index]] = temp;
        index++;
    }
    return constantTemps;

}


