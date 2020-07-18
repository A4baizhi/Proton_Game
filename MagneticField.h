#ifndef _MagneticField_h_
#define _MagneticField_h_
#include "Proton.h"
class MagneticField
{
    private:
        double strength = 10;
        bool direction = true;
        Point centerPoint;
        int radius;
    public:
        //static int numberOfMagneticFieldfield;
        MagneticField();
        MagneticField(Point O,int R);
        ~MagneticField();
        bool isInField(Proton &proton);
        void addSpeed(Proton &proton);
        void addStrength(double delta);
        void changeStrength(double newStrength);
        void changeDirection(bool out);
};
#endif
