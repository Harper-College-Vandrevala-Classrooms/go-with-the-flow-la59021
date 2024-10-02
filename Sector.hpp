
class Sector {
    public:
        Sector(int initalType, double initalTemp);
        void setTemp(double newTemp);
        double getTemp();
        int getType();

    private:
        double temp;
        int type;
};
