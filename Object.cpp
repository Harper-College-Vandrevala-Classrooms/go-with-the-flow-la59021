#include "Object.hpp"
using namespace std;

Object::Object(double initalTemp, double rodLength, double kConstant, vector<int> sources, vector<int> sinks) {
    int sections = sources.size();
    localSources = sources;
    localSinks = sinks;
    for (int x = 0; x < sections; x++) {
        localObject.push_back(Sector());
    }
}

int Object::getSections() {
    return localSources.size();
}
