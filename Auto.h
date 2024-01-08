#ifndef AUTO_H
#define AUTO_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;


class Auto : public BaseObject
{
    private:
        float posOriginalX, posOriginalY;
        bool direccion;

    public:
        Auto(float posX, float Y, bool direccion);
        ~Auto();

        void move(Vector2u tamanioVentana);
        float getPosOriginalX() { return this->posOriginalX; }
        float getPosOriginalY() { return this->posOriginalY; }

    protected:

};

#endif // AUTO_H
