
#ifndef _Finish_cpp_
#define _Finish_cpp_
#include "Finish.h"
#include <QMessageBox>

Finish::Finish(){return;};
Finish::Finish(Point A,Point B){
    theFirstPoint = A;
    theSecondPoint = B;
    return;
};
Finish::~Finish(){};
bool Finish::isInField(Proton &proton){
    return (theFirstPoint.isAbove(proton) ^ theSecondPoint.isAbove(proton)) & (theFirstPoint.isLeft(proton) ^ theSecondPoint.isLeft(proton));
};
void Finish::hitted(Proton &proton){
    if(isInField(proton)){
        //proton.InitializeProton();
        QMessageBox msgbox;
        msgbox.setWindowTitle("提示");
        msgbox.setText("游戏结束");
        msgbox.exec();
    }
};
#endif

