#include "BarreraJersey.h"
#include "DEFINITIONS.h"
#include "Derrota.h"

using namespace sf;

BarreraJersey::BarreraJersey(float tamVentana, float posX, float posY)
{
    if (barrera.empty())
    {
        barrera.push_back(new Tiles(0.0f, posY, 14));
    } else {
        barrera.push_back(new Tiles(barrera.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 14));
    }

    while (barrera.back()->getShape().getPosition().x < tamVentana)
    {
        barrera.push_back(new Tiles(barrera.back()->getShape().getPosition().x + ANCHO_BARRERA, posY, 14));

        if (barrera.size() % 4 == 0)
        {
                barrera.push_back(new Tiles(barrera.back()->getShape().getPosition().x + ESPACIO_ENTRE_CUADRAS, posY, 14));
        }
    }
}

void BarreraJersey::draw(RenderWindow& window) {
    for (auto& newJersey : barrera) {
        newJersey->draw(window);
    }
}

bool BarreraJersey::checkCollision(Personaje* personaje, sf::RenderWindow& window) {
    for (auto& newJersey : barrera) {
        if (personaje->getShape().getGlobalBounds().intersects(newJersey->getShape().getGlobalBounds())) {
            return true;  // Colisión detectada
        }
    }
    return false;  // No hay colisión
}
