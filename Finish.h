
#ifndef FINISH_H
#define FINISH_H
#include "Proton.h"

class Finish
{
    private:
        Point theFirstPoint;
        Point theSecondPoint;
    public:
        Finish();
        Finish(Point A,Point B);
        ~Finish();
        bool isInField(Proton &proton);
        void hitted(Proton &proton);
};
#endif // FINISH_H

