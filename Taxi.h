#ifndef TAXI_H
#define TAXI_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;

class Taxi : public BaseObject
{
    private:
        float posOriginalX, posOriginalY;
        bool direccion;

    public:
        Taxi(float posX, float posY, bool direccion);
        ~Taxi();

        void move(Vector2u tamanioVentana);
        float getPosOriginalX() { return this->posOriginalX; }
        float getPosOriginalY() { return this->posOriginalY; }

};

#endif // TAXI_H
