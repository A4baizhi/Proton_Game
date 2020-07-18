#ifndef _ElectricField_h_
#define _ElectricField_h_
#include "Proton.h"
class ElectricField
{
    private:
        double strength = 10000;
        degree direction = 0;
        Point theFirstPoint;
        Point theSecondPoint;
    public:
        //static int numberOfElectricField;
        ElectricField();
        ElectricField(Point A,Point B);
        ~ElectricField();
        bool isInField(Proton &proton);
        void addSpeed(Proton &proton);
        void addStrength(double delta);
        void addDircetion(double delta);
        void changeStrength(double newStrength);
        void changeDirection(double newDirection);
};
#endif
