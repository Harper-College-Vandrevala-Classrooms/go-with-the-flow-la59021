#include <iostream>
#include "HeatFlow.hpp"
using namespace std;

HeatFlow::HeatFlow(double initalTemp, double rodLength, double kConstant) {
    Object localObject = createObject(initalTemp, rodLength, kConstant);
    pretty_print();
    tick(localObject);
}

void HeatFlow::tick(Object localObject) {
    //Progress Heat Flow
}

void HeatFlow::pretty_print() {
    string row1;
    for (int x = 0; x < sections; x++) {
        row1 += "|1";
    }
    row1 += "|";
    cout << row1 << endl;
}

void HeatFlow::askHowManySections() {
    cout << "How many sections will there be?" << endl;
    cin >> sections;
}

int HeatFlow::askHowManySources() {
    cout << "How many sources will there be?" << endl;
    int qSources;
    cin >> qSources;
    return qSources;
}

vector<int> HeatFlow::askWhereTheSourcesAre(int q, int length) {
    vector<int> sources;
    int index = 0;
    for (int x = 0; x < q; x++) {
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
        sources.push_back(index);
    }
    return sources;
}

int HeatFlow::askHowManySinks() {
    cout << "How many sinks will there be?" << endl;
    int qSinks;
    cin >> qSinks;
    return qSinks;
}

vector<int> HeatFlow::askWhereTheSinksAre(int q, int length) {
    vector<int> sinks;
    int index = 0;
    for (int x = 0; x < q; x++) {
        if (x == 0) {
            cout << "What is the index of the 1st sink?" << endl;
            cin >> index;
        }
        else if (x == 1) {
            cout << "What is the index of the 2nd sink?" << endl;
            cin >> index;
        }
        else if (x == 2) {
            cout << "What is the index of the 3rd sink?" << endl;
            cin >> index;
        }
        else {
            cout << "What is the index of the " << x+1 << "th sink?" << endl;
            cin >> index;
        }
        sinks.push_back(index);
    }
    return sinks;
}

vector<Sector> HeatFlow::createObject(double initalTemp, double rodLength, double kConstant) {
    askHowManySections();
    int qSources = askHowManySources();
    vector<int> sources;
    vector<int> sinks;
    if (qSources != 0) {
         sources = askWhereTheSourcesAre(qSources, sections);
    }
    int qSinks = askHowManySinks();
    if (qSinks != 0) {
        sinks = askWhereTheSinksAre(qSinks, sections);
    }
    vector<Sector> localObject;
    for (int x = 0; x < sections; x++) {
        localObject.push_back()
    }
    return localObject;
}
