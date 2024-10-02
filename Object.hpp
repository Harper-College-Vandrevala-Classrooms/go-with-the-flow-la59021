#include <vector>
#include "Sector.hpp"
using namespace std;

class Object {
    public:
        Object(double initalTemp, double rodLength, double kConstant, vector<int> sources, vector<int> sinks);
        int getSections();
        vector<int> getSources();
        void setSources(vector<int> newSources);
        vector<int> getSinks();
        void setSinks(vector<int> newSinks);
    private:
        double localInitalTemp;
        double localRodLength;
        double localK;
        vector<Sector> localObject;
        vector<int> localSources;
        vector<int> localSinks;

};
