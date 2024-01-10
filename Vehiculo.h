#ifndef VEHICULO_H
#define VEHICULO_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "DEFINITIONS.h"

using namespace sf;

class Vehiculo : public BaseObject
{
    protected:
        float posOriginalX, posOriginalY;
        bool direccion;

    public:
        Vehiculo(float posX, float Y, bool direccion);

        virtual void move(const Vector2u tamanioVentana) = 0;
        float getPosOriginalX() { return this->posOriginalX; }
        float getPosOriginalY() { return this->posOriginalY; }

};

#endif // VEHICULO_H
