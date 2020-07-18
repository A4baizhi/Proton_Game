#ifndef _Speed_h_
#define _Speed_h_
#include <cmath>
const double tick = 0.01;
const double degreeUnit = 1000.0;           //角度单位
const double PI = 3.1416;
const double transRtoT = 180.0 / PI;
typedef int degree;                         //x度角表示为degreeUnit*x
class Speed
{
    protected:
        double speedX;                          //横向速度
        double speedY;                          //纵向速度
        double speed;                           //和速度
        degree speedDirection;                  //速度方向
    public:
        Speed();
        ~Speed();
        void transformSpeedByXY();                       //通过横向速度和纵向速度来调整和速度和速度方向
        void transformSpeedByRT();                       //通过速度大小和方向计算横向速度和纵向速度
        void changeSpeedByNormalForce(double normalSpeed);             //通过法向力改变速度大小和方向
        void addSpeedX(double delta);
        void addSpeedY(double delta);
        double getSpeed();                           //返回速度大小
        double getDirection();
};
#endif
