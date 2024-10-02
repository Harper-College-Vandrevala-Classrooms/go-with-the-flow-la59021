#include <cassert>
#include <iostream>
#include <fstream>
#include "HeatFlow.hpp"
using namespace std;

void printToFile() {
ofstream myfile;
    myfile.open("log.txt");
    vector<double> stats {10, 8, 0.1}; // inital temp, rod length, K
    vector<bool> sourceOrSink {true, false, false, false, false, false, false, false};
    vector<double> constantTemps {100, 0, 0, 0, 0, 0, 0, 0};
    HeatFlow h(stats, sourceOrSink, constantTemps);
    string startString = h.getCurrentTemps();
    char start = startString[startString.size()-3];
    myfile << h.getCurrentTemps() << endl;
    while (start != '.') {
        h.tick();
        myfile << h.getCurrentTemps() << endl;
        startString = h.getCurrentTemps();
        start = startString[startString.size()-3];
    }
    myfile.close();
}

void testA() {
    vector<double> stats {10, 8, 0.1}; // inital temp, rod length, K
    vector<bool> sourceOrSink {true, false, false, false, false, false, false, false};
    vector<double> constantTemps {100, 0, 0, 0, 0, 0, 0, 0};
    HeatFlow h(stats, sourceOrSink, constantTemps);
    h.pretty_print();
    assert(h.getCurrentTemps() == "100.00, 10.000, 10.000, 10.000, 10.000, 10.000, 10.000, 10.000");
    h.tick();
    h.pretty_print();
    assert(h.getCurrentTemps() == "100.00, 19.000, 10.000, 10.000, 10.000, 10.000, 10.000, 10.000");
    h.tick();
    h.pretty_print();
    assert(h.getCurrentTemps() == "100.00, 26.200, 10.900, 10.000, 10.000, 10.000, 10.000, 10.000");
    h.tick();
    h.pretty_print();
    assert(h.getCurrentTemps() == "100.00, 32.050, 12.340, 10.090, 10.000, 10.000, 10.000, 10.000");
    h.tick();
    cout << h.getCurrentTemps();
}

void testB() {

}


int main() {
    printToFile();
    //testA();
    return 0;
}
