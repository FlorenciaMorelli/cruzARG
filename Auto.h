#ifndef AUTO_H
#define AUTO_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;


class Auto : public BaseObject
{
    private:
        float posOriginalX, posOriginalY;

    public:
        Auto(float posX, float Y);
        ~Auto();

        void move();
        float getPosOriginalX() { return this->posOriginalX; }
        float getPosOriginalY() { return this->posOriginalY; }

    protected:

};

#endif // AUTO_H
