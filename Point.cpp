#ifndef _Point_cpp_
#define _Point_cpp_
#include<QDebug>
#include"Point.h"

Point::Point(){x = 0;y = 0;return;}
Point::Point(double X,double Y){x = X;y = Y;return;}
Point::~Point(){return;};
void Point::getPoint(){qDebug()<<'('<<x<<','<<y<<')';return;}
void Point::changeX(double newX){x = newX;return;}
void Point::changeY(double newY){y = newY;return;}
void Point::addX(double addX){x += addX;return;}
void Point::addY(double addY){y += addY;return;}
void Point::changeP(double newX,double newY){x = newX;y = newY;return;}
double Point::operator-(Point pointB){
    return sqrt((pointB.x - x)*(pointB.x - x) + (pointB.y - y)*(pointB.y - y));
    }
bool Point::isAbove(Point PointB){return x > PointB.x;}
bool Point::isLeft(Point PointB){return y < PointB.y;}
int Point::X(){return x;}
int Point::Y(){return y;}
QPoint Point::operator=(QPoint A){x = A.x();y = A.y();return A;};
#endif
