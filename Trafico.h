#ifndef TRAFICO_H
#define TRAFICO_H

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Auto.h"
#include "Taxi.h"
#include "Colectivo.h"
#include "Personaje.h"

using namespace sf;

class Trafico
{
    private:
        std::vector<Vehiculo*> vehiculos;

    public:
        Trafico(int tipo, float tamVentana, float posY, bool direccion);

        void move(const Vector2u& tamVentana);
        void draw(RenderWindow& window);
        bool checkCollision(Personaje* personaje, RenderWindow& window);

};

#endif // TRAFICO_H
