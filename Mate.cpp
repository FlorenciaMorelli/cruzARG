#include "Mate.h"

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Mate::Mate(Vector2u tamanioVentana)
{
    shape.setSize(Vector2f(TAMANO_MATE, TAMANO_MATE));
    this->shapeTexture.loadFromFile("./assets/mate.png");
    shape.setTexture(&shapeTexture);

    srand(time(NULL));

    int posX = std::rand() % static_cast<int>(tamanioVentana.x - TAMANO_MATE) + 1;

    shape.setPosition(Vector2f(posX, TAMANO_MATE * 2));
    shape.setOrigin(TAMANO_MATE / 2, TAMANO_MATE / 2);
}

bool Mate::tomado(Personaje* personaje, RenderWindow& window)
{
    if (personaje->getShape().getGlobalBounds().intersects(shape.getGlobalBounds())) {
            Victoria ganaste(window);
            ganaste.ganador(window);
            return true;
    }

    return false;
}
