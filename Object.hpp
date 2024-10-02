#include <vector>
using namespace std;

class Object {
    public:
        Object();
        void setObject(vector<double> Stats, vector<bool> sourceOrSink, vector<double> Temps);
        void tick();
        void pretty_print();
        vector<double> getCurrentRod();
    private:
        vector<double> rodStats; // inital temp, rod length, K
        vector<double> currentRod; // current temps
        vector<double> nextRod; // next temps
        vector<bool> constants; // is source or sink (held constant)
        vector<double> constantTemps; // temps constants are held at
};
