#include "Sector.hpp"
using namespace std;

class HeatFlow {
    public:
        HeatFlow(double initalTemp, double rodLength, double kConstant);
        void tick(Object localObject);
        void pretty_print();

    private:
        void askHowManySections();
        int askHowManySources();
        vector<int> askWhereTheSourcesAre(int q, int length);
        int askHowManySinks();
        vector<int> askWhereTheSinksAre(int q, int length);
        vector<Sector> createObject(double initalTemp, double rodLength, double kConstant);
        int sections;
};
