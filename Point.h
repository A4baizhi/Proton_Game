#ifndef _Point_h_
#define _Point_h_
#include <cmath>
#include <QPoint>
class Point
{
    private:
        double x;
        double y;
    public:
        Point();
        Point(double X,double Y);
        ~Point();
        void getPoint();
        void changeX(double newX);          //设置横坐标为newX
        void changeY(double newY);          //设置纵坐标为newY
        void addX(double addX);             //使横坐标增加addX
        void addY(double addY);             //使纵坐标增加addY
        void changeP(double newX,double newY);//将点设置为(newX,newY)
        double operator-(Point pointB);     //将返回该点到pointB的距离
        bool isAbove(Point pointB);         //该点是否在B点上方？
        bool isLeft(Point pointB);          //该点是否在B点左方？
        QPoint operator=(QPoint A);
        int X();
        int Y();
    friend class ElectricField;
    friend class MagneticField;
};
#endif
