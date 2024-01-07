#ifndef TAXI_H
#define TAXI_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;

class Taxi : public BaseObject
{
    private:
        float posOriginalX, posOriginalY;

    public:
        Taxi(float posX, float posY, Texture texture);
        ~Taxi();

        void move(Vector2u tamanioVentana);
};

#endif // TAXI_H
