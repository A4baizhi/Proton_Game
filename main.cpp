#include "widget.h"
#include "Proton.h"
#include "ElectricField.h"
#include "MagneticField.h"
#include "Finish.h"
#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <iostream>
void setProton(Widget &w){
    Proton P(50,50);
    P.setMass(1);
    P.setQuantity(1);
    w.ProtonList<<P;
    return;
}
BarrierPic GenerateBarrier(int Ax,int Ay,int Bx,int By){
    Point A(Ax,Ay);
    Point B(Bx,By);
    Barrier Ba(A,B);
    QRect rect(Ax,Ay,Bx-Ax,By-Ay);
    BarrierPic result = {Ba,rect};
    return result;
};
FinishPic GenerateFinish(int Ax,int Ay,int Bx,int By){
    Point A(Ax,Ay);
    Point B(Bx,By);
    Finish Ba(A,B);
    QRect rect(Ax,Ay,Bx-Ax,By-Ay);
    FinishPic result = {Ba,rect};
    return result;
};
void setBaseBarrier(Widget &w){
    w.BarrierList<<GenerateBarrier(0,0,1200,20);
    w.BarrierList<<GenerateBarrier(0,0,20,800);
    w.BarrierList<<GenerateBarrier(1180,0,1200,800);
    w.BarrierList<<GenerateBarrier(0,780,1200,800);
    w.numberOfBarrier += 4;
}
void setBarrier(Widget &w){
    w.BarrierList<<GenerateBarrier(400,0,420,300);
    w.BarrierList<<GenerateBarrier(400,800,420,500);
    w.BarrierList<<GenerateBarrier(600,200,620,600);
    w.BarrierList<<GenerateBarrier(800,0,820,300);
    w.BarrierList<<GenerateBarrier(820,500,800,800);
    w.numberOfBarrier += 5;
}
void setEnd(Widget &w){
    w.FinishList<<GenerateFinish(1160,500,1180,300);
    w.numberOfFinish += 1;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(1200,850);
    w.setFixedSize(w.width(),w.height());
    w.setWindowTitle(QObject::tr("Porton"));
    setProton(w);
    setBaseBarrier(w);
    setBarrier(w);
    setEnd(w);
    QLabel label(&w);
    label.setText(QObject::tr("Proton"));
    w.ProtonList[0].InitializeProton();
    w.show();

    return a.exec();
}
