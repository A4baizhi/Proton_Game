#ifndef _MagneticField_cpp_
#define _MagneticField_cpp_
#include "MagneticField.h"
#include <iostream>
MagneticField::MagneticField(){
    //MagneticFieldfield::numberOfMagneticFieldfield ++ ;
    return;
};
MagneticField::MagneticField(Point O,int R){
    centerPoint = O;
    radius = R;
    //MagneticFieldfield::numberOfMagneticFieldfield -- ;
    return;
};
MagneticField::~MagneticField(){
    //MagneticFieldfield::numberOfMagneticFieldfield -- ;
    return;
};
bool MagneticField::isInField(Proton &proton){
    return proton - centerPoint < radius;
};
void MagneticField::addSpeed(Proton &proton){
    if(isInField(proton)){
        double deltaSpeed;
        deltaSpeed = strength * proton.getSpecificCharge() * proton.getSpeed() * tick;
        if(!direction) deltaSpeed = - deltaSpeed;
        proton.changeSpeedByNormalForce(deltaSpeed);
        proton.transformSpeedByRT();
        return;
    }
    else {
        //std::cout<<"不在磁场内";
        return;
    }
};
void MagneticField::addStrength(double delta){
    strength += delta;
};
void MagneticField::changeStrength(double newStrength){
    strength = newStrength;
};

#endif