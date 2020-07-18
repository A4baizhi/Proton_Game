#ifndef _Barrier_cpp_
#define _Barrier_cpp_
#include "Barrier.h"
Barrier::Barrier(){return;};
Barrier::Barrier(Point A,Point B){
    theFirstPoint = A;
    theSecondPoint = B;
    return;
};
Barrier::~Barrier(){};
bool Barrier::isInField(Proton &proton){
    return (theFirstPoint.isAbove(proton) ^ theSecondPoint.isAbove(proton)) & (theFirstPoint.isLeft(proton) ^ theSecondPoint.isLeft(proton));
};
void Barrier::hitted(Proton &proton){
    if(isInField(proton)){
        proton.InitializeProton();
    }
};
#endif
