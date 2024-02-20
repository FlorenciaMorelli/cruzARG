#ifndef AUTO_H
#define AUTO_H

#include <SFML/Graphics.hpp>
#include "Vehiculo.h"

using namespace sf;


class Auto : public Vehiculo
{
    public:
        Auto(float posX, float posY, bool direccion);

        void move(const Vector2u tamanioVentana);
};

#endif // AUTO_H
