#include <string>
#include "Object.hpp"
using namespace std;

class HeatFlow {
    public:
        HeatFlow();
        HeatFlow(vector<double> stats, vector<bool> sourceOrSink, vector<double> constantTemps);
        HeatFlow(double initalTemp, int rodLength, double kConstant, vector<bool> sourceOrSink, vector<double> constantTemps);
        void tick();
        void pretty_print();
        string getCurrentTemps();
    private:
        vector<double> askForStats();
        int askHowManyConstants();
        vector<bool> askWhereTheConstantsAre(int numOfConstants, int rodLength);
        vector<double> askWhatConstantTempsAre(int numOfConstants, int rodLength, vector<bool> constants);
        Object o;
};
