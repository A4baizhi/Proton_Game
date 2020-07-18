#ifndef _ElectricField_cpp_
#define _ElectricField_cpp_
#include <QPainter>
#include "ElectricField.h"
ElectricField::ElectricField(){
    theFirstPoint.changeP(0,0);
    theSecondPoint.changeP(0,0);
    //ElectricField::numberOfElectricField ++ ;
    return;
};
ElectricField::ElectricField(Point A,Point B){
    theFirstPoint = A;
    theSecondPoint = B;
    //ElectricField::numberOfElectricField ++ ;
    return;
};
ElectricField::~ElectricField(){
    //ElectricField::numberOfElectricField -- ;
};
bool ElectricField::isInField(Proton &proton){
    return (theFirstPoint.isAbove(proton) ^ theSecondPoint.isAbove(proton)) & (theFirstPoint.isLeft(proton) ^ theSecondPoint.isLeft(proton));
};
void ElectricField::addSpeed(Proton &proton){
    if(isInField(proton)){
        direction %= 360;
        double deltaSpeed = strength * proton.getSpecificCharge() * tick;
        proton.addSpeedX(deltaSpeed * cos(direction/degreeUnit /transRtoT));
        proton.addSpeedY(deltaSpeed * sin(direction/degreeUnit /transRtoT));
        proton.transformSpeedByXY();
        return;
    }
    else{
        //std::cout<<"不在电场内";
        return;
    }
};
void ElectricField::addStrength(double delta){
    strength += delta;
    return;
};
void ElectricField::addDircetion(double delta){
    direction += delta * degreeUnit;
    direction %= 360 * int(degreeUnit);
    return;
};
void ElectricField::changeStrength(double newStrength){
    strength = newStrength;
    return;
}
void ElectricField::changeDirection(double newDirection){
    direction = newDirection;
    return;
}
#endif
