#include <cassert>
#include <iostream>
#include "HeatFlow.hpp"
using namespace std;

void testA() {
    cout << "First tests, the inital temperture is set to 10, there are 8 sections and the K is set to 0.1" << endl;
    cout << "There is a source set to 100 at index 0." << endl;
    vector<double> stats {10, 8, 0.1}; // inital temp, rod length, K
    vector<bool> sourceOrSink {true, false, false, false, false, false, false, false};
    vector<double> constantTemps {100, 0, 0, 0, 0, 0, 0, 0};
    HeatFlow h(stats, sourceOrSink, constantTemps);
    assert(h.getCurrentTemps() == "100.00, 10.000, 10.000, 10.000, 10.000, 10.000, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 19.000, 10.000, 10.000, 10.000, 10.000, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 26.200, 10.900, 10.000, 10.000, 10.000, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 32.050, 12.340, 10.090, 10.000, 10.000, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 36.874, 14.086, 10.306, 10.009, 10.000, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 40.907, 15.986, 10.654, 10.037, 10.000, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 44.324, 17.945, 11.125, 10.095, 10.004, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 47.254, 19.901, 11.704, 10.189, 10.013, 10.000, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 49.793, 21.817, 12.373, 10.323, 10.029, 10.001, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 52.016, 23.670, 13.112, 10.499, 10.056, 10.004, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 53.980, 25.449, 13.906, 10.716, 10.095, 10.009, 10.000");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 55.729, 27.148, 14.742, 10.973, 10.148, 10.016, 10.001");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 57.298, 28.765, 15.605, 11.267, 10.218, 10.028, 10.003");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 58.715, 30.302, 16.487, 11.596, 10.304, 10.044, 10.005");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 60.002, 31.762, 17.380, 11.956, 10.407, 10.066, 10.009");
    cout << h.getCurrentTemps() << endl;
    h.tick();
    assert(h.getCurrentTemps() == "100.00, 61.178, 33.148, 18.276, 12.343, 10.528, 10.095, 10.015");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 62.257, 34.464, 19.170, 12.755, 10.666, 10.130, 10.023");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 63.252, 35.714, 20.058, 13.188, 10.821, 10.173, 10.033");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 64.173, 36.902, 20.936, 13.638, 10.993, 10.224, 10.047");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 65.028, 38.032, 21.803, 14.103, 11.181, 10.283, 10.065");
}

void testB() {
    cout << endl << "Second tests, the inital temperture is set to 100, there are 20 sections and the K is set to 0.5" << endl;
    cout << "There are constants at indexes 5 and 9, they are set to 5 and 200 respectivly." << endl;
    vector<double> stats {100, 20, 0.5}; // inital temp, rod length, K
    vector<bool> sourceOrSink(20, false);
    sourceOrSink[5] = true;
    sourceOrSink[9] = true;
    vector<double> constantTemps(20, 0);
    constantTemps[5] = 5;
    constantTemps[9] = 200;
    HeatFlow h(stats, sourceOrSink, constantTemps);
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 100.00, 100.00, 100.00, 100.00, 5.0000, 100.00, 100.00, 100.00, 200.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 100.00, 100.00, 100.00, 52.500, 5.0000, 52.500, 100.00, 150.00, 200.00, 150.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 100.00, 100.00, 76.250, 52.500, 5.0000, 52.500, 101.25, 150.00, 200.00, 150.00, 125.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 100.00, 88.125, 76.250, 40.625, 5.0000, 53.125, 101.25, 150.62, 200.00, 162.50, 125.00, 112.50, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "100.00, 94.062, 88.125, 64.375, 40.625, 5.0000, 53.125, 101.87, 150.62, 200.00, 162.50, 137.50, 112.50, 106.25, 100.00, 100.00, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "97.031, 94.062, 79.218, 64.375, 34.687, 5.0000, 53.437, 101.87, 150.93, 200.00, 168.75, 137.50, 121.87, 106.25, 103.12, 100.00, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "95.546, 88.125, 79.218, 56.953, 34.687, 5.0000, 53.437, 102.18, 150.93, 200.00, 168.75, 145.31, 121.87, 112.50, 103.12, 101.56, 100.00, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "91.835, 87.382, 72.539, 56.953, 30.976, 5.0000, 53.593, 102.18, 151.09, 200.00, 172.65, 145.31, 128.90, 112.50, 107.03, 101.56, 100.78, 100.00, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "89.609, 82.187, 72.167, 51.757, 30.976, 5.0000, 53.593, 102.34, 151.09, 200.00, 172.65, 150.78, 128.90, 117.96, 107.03, 103.90, 100.78, 100.39, 100.00, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "85.898, 80.888, 66.972, 51.572, 28.378, 5.0000, 53.671, 102.34, 151.17, 200.00, 175.39, 150.78, 134.37, 117.96, 110.93, 103.90, 102.14, 100.39, 100.19, 100.00");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "83.393, 76.435, 66.230, 47.675, 28.286, 5.0000, 53.671, 102.42, 151.17, 200.00, 175.39, 154.88, 134.37, 122.65, 110.93, 106.54, 102.14, 101.17, 100.19, 100.09");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "79.914, 74.812, 62.055, 47.258, 26.337, 5.0000, 53.710, 102.42, 151.21, 200.00, 177.44, 154.88, 138.76, 122.65, 114.59, 106.54, 103.85, 101.17, 100.63, 100.14");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "77.363, 70.985, 61.035, 44.196, 26.129, 5.0000, 53.710, 102.46, 151.21, 200.00, 177.44, 158.10, 138.76, 126.68, 114.59, 109.22, 103.85, 102.24, 100.65, 100.39");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "74.174, 69.199, 57.590, 43.582, 24.598, 5.0000, 53.730, 102.46, 151.23, 200.00, 179.05, 158.10, 142.39, 126.68, 117.95, 109.22, 105.73, 102.25, 101.31, 100.52");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "71.686, 65.882, 56.390, 41.094, 24.291, 5.0000, 53.730, 102.48, 151.23, 200.00, 179.05, 160.72, 142.39, 130.17, 117.95, 111.84, 105.74, 103.52, 101.39, 100.92");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "68.784, 64.038, 53.488, 40.340, 23.047, 5.0000, 53.740, 102.48, 151.24, 200.00, 180.36, 160.72, 145.44, 130.17, 121.01, 111.84, 107.68, 103.56, 102.22, 101.15");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "66.411, 61.136, 52.189, 38.267, 22.670, 5.0000, 53.740, 102.49, 151.24, 200.00, 180.36, 162.90, 145.44, 133.23, 121.01, 114.34, 107.70, 104.95, 102.36, 101.69");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "63.774, 59.300, 49.702, 37.430, 21.633, 5.0000, 53.745, 102.49, 151.24, 200.00, 181.45, 162.90, 148.06, 133.23, 123.78, 114.36, 109.65, 105.03, 103.32, 102.02");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "61.537, 56.738, 48.365, 35.668, 21.215, 5.0000, 53.745, 102.49, 151.24, 200.00, 181.45, 164.76, 148.06, 135.92, 123.79, 116.72, 109.69, 106.48, 103.53, 102.67");
    h.tick();
    cout << h.getCurrentTemps() << endl;
    assert(h.getCurrentTemps() == "59.137, 54.951, 46.203, 34.790, 20.334, 5.0000, 53.747, 102.49, 151.24, 200.00, 182.38, 164.76, 150.34, 135.93, 126.32, 116.74, 111.60, 106.61, 104.58, 103.10");
}

int main() {
    testA();
    //printToFile();
    testB();

    return 0;
}
