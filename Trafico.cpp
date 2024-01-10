#include "Trafico.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "DEFINITIONS.h"
#include <vector>

Trafico::Trafico(float tamVentana, float posY, bool direccion) {
    float posX = 0.0;
    if(direccion){
        posX = -ANCHO_AUTO;

        vehiculos.push_back(new Taxi(posX, posY, direccion));

        for (int i = 1; i < 12; ++i) {
            float nuevaPosicionX = vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS +
                                   rand() % (int)(SEPARACION_PARA_PERSONAJE - SEPARACION_ENTRE_VEHICULOS + 1);

            if (nuevaPosicionX + ANCHO_AUTO <= tamVentana) {
                if (rand() % 2 == 0) {
                    vehiculos.push_back(new Taxi(nuevaPosicionX, posY, direccion));
                } else {
                    vehiculos.push_back(new Auto(nuevaPosicionX, posY, direccion));
                }
            } else {
                break;
            }
        }
    } else {
        posX = tamVentana + ANCHO_TAXI;

        vehiculos.push_back(new Taxi(posX, posY, direccion));

        for (int i = 1; i < 12; ++i) {
            float nuevaPosicionX = vehiculos.back()->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS -
                                   rand() % (int)(SEPARACION_PARA_PERSONAJE - SEPARACION_ENTRE_VEHICULOS + 1);

            if (nuevaPosicionX - ANCHO_AUTO >= 0.0) {
                if (rand() % 2 == 0) {
                    vehiculos.push_back(new Taxi(nuevaPosicionX, posY, direccion));
                } else {
                    vehiculos.push_back(new Auto(nuevaPosicionX, posY, direccion));
                }
            } else {
                break;
            }
        }

    }
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
