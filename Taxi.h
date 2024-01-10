#ifndef TAXI_H
#define TAXI_H

#include <SFML/Graphics.hpp>
#include "Vehiculo.h"

using namespace sf;

class Taxi : public Vehiculo
{
    public:
        Taxi(float posX, float posY, bool direccion);

        void move(Vector2u tamanioVentana);
};

#endif // TAXI_H
