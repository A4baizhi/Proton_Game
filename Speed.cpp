#ifndef _Speed_cpp_
#define _Speed_cpp_
#include "Speed.h"
Speed::Speed(){};
Speed::~Speed(){};
void Speed::transformSpeedByXY(){
    speed = sqrt(speedX*speedX + speedY*speedY);
    speedDirection = degreeUnit*atan2(speedY , speedX) * transRtoT;
    return;
};                                      //通过横向速度和纵向速度来调整和速度和速度方向
void Speed::transformSpeedByRT(){
    speedX = speed * sin(speedDirection/degreeUnit /transRtoT);
    speedY = speed * cos(speedDirection/degreeUnit /transRtoT);
    return;
};                                      //通过速度大小和方向计算横向速度和纵向速度
double Speed::getSpeed(){
    return speed;
};
void Speed::addSpeedX(double delta){
    speedX += delta;
    return;
};
void Speed::addSpeedY(double delta){
    speedY += delta;
    return;
};
void Speed::changeSpeedByNormalForce(double normalSpeed){
    speedDirection += atan2(normalSpeed , speed)*transRtoT * degreeUnit; 
    //speed = sqrt(normalSpeed * normalSpeed + speed * speed);
};
double Speed::getDirection(){
    return speedDirection/degreeUnit;
}
#endif