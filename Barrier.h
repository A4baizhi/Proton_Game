#ifndef _Barrier_h_
#define _Barrier_h_
#include "Proton.h"

class Barrier
{
    private:
        Point theFirstPoint;
        Point theSecondPoint;
    public:
        Barrier();
        Barrier(Point A,Point B);
        ~Barrier();
        bool isInField(Proton &proton);
        void hitted(Proton &proton);
};
#endif
