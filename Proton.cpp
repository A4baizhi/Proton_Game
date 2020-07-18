#ifndef _Proton_cpp_
#define _Proton_cpp_
#include "Proton.h"
Proton::Proton(){
    changeP(0,0);
    //Proton::numOfProton ++ ;
    return;
};
Proton::Proton(double X,double Y){
    changeP(X,Y);
    //Proton::numOfProton ++ ;
    return;
};
Proton::~Proton(){
    //Proton::numOfProton -- ;
    return;
};
void Proton::move(){
    addX(speedX * tick);
    addY(speedY * tick);
    return;
};
double Proton::getSpecificCharge(){
    return quantityOfElectric / mass;
};
void Proton::setMass(double m){
    mass = m;
    return;
};
void Proton::setQuantity(double q){
    quantityOfElectric = q;
    return;
};
void Proton::clearSpeed(){
    speedX = 0;
    speedY = 0;
    transformSpeedByXY();
    return;
}
void Proton::InitializeProton(){
    //changeP(50,50);
    //changeP(1000,400);
    changeP(800,400);
    clearSpeed();
};
#endif
