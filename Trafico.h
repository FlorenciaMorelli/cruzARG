#ifndef TRAFICO_H
#define TRAFICO_H

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Auto.h"
#include "Taxi.h"
#include "Personaje.h"

using namespace sf;

class Trafico {
public:
    Trafico(float tamVentana, float posY, bool direccion);

    void move(const Vector2u& tamVentana);
    void draw(RenderWindow& window);
    bool checkCollision(Personaje* personaje, RenderWindow& window);

private:
    std::vector<Vehiculo*> vehiculos;
};

#endif // TRAFICO_H
