#ifndef VEHICULOS_H
#define VEHICULOS_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;


class Vehiculos : public BaseObject
{
    protected:
        float posOriginalX, posOriginalY;
        bool direccion;

    public:
        Vehiculos(float posX, float posY, bool direccion);

        virtual void move(Vector2u tamanioVentana) = 0;
        float getPosOriginalX() { return this->posOriginalX; }
        float getPosOriginalY() { return this->posOriginalY; }


};

#endif // VEHICULOS_H
