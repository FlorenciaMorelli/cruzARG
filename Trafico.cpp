#include "Trafico.h"

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include <vector>

Trafico::Trafico(float posX, float posY, bool direccion) {
    vehiculos.push_back(new Taxi(posX, posY, direccion));
    vehiculos.push_back(new Taxi(vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, posY, direccion));
    vehiculos.push_back(new Auto(vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, posY, direccion));
    vehiculos.push_back(new Taxi(vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, posY, direccion));
    vehiculos.push_back(new Auto(vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, posY, direccion));
    vehiculos.push_back(new Auto(vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS, posY, direccion));
}

void Trafico::move(const sf::Vector2u& tamVentana) {
    for (auto& vehiculo : vehiculos) {
        vehiculo->move(tamVentana);
    }
}

void Trafico::draw(sf::RenderWindow& window) {
    for (auto& vehiculo : vehiculos) {
        vehiculo->draw(window);
    }
}

bool Trafico::checkCollision(Personaje* personaje, sf::RenderWindow& window) {
    for (auto& vehiculo : vehiculos) {
        if (personaje->getShape().getGlobalBounds().intersects(vehiculo->getShape().getGlobalBounds())) {
            window.close();
            return true;  // Colisión detectada
        }
    }
    return false;  // No hay colisión
}
