#ifndef _Proton_h_
#define _Proton_h_
#include "Point.h"
#include "Speed.h"

class Proton:public Point,public Speed
{
    private:
        double quantityOfElectric;
        double mass;
    public:
        //static int numOfProton;
        Proton();
        Proton(double X,double Y);
        ~Proton();
        void setMass(double m);
        void setQuantity(double q);
        double getSpecificCharge();
        void clearSpeed();
        void InitializeProton();
        //void transformSpeedByXY();
        //void transformSpeedByRT();
        //double getSpeed();
        void move();
};
#endif
