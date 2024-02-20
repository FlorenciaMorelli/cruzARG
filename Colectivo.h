#ifndef COLECTIVO_H
#define COLECTIVO_H

#include <Vehiculo.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Colectivo : public Vehiculo
{
    public:
        Colectivo(float posX, float posY, bool direccion);

        void move(Vector2u tamanioVentana);
};

#endif // COLECTIVO_H
