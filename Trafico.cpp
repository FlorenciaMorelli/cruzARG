#include "Trafico.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "DEFINITIONS.h"
#include <vector>
#include "Derrota.h"

using namespace sf;

Trafico::Trafico(int tipo, float tamVentana, float posY, bool direccion)
{
    float posX = 0.0;
    if(tipo == 1){
        if(direccion){
            posX = -ANCHO_AUTO;

            vehiculos.push_back(new Taxi(posX, posY, direccion));

            for (int i = 1; i < 12; i++) {
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

            for (int i = 1; i < 12; i++) {
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
    } else if(tipo == 2){
        if(direccion){
            posX = -ANCHO_COLECTIVO;

            vehiculos.push_back(new Colectivo(posX, posY, direccion));

            for (int i = 1; i < 7; i++) {
                float nuevaPosicionX = vehiculos.back()->getPosOriginalX() + SEPARACION_ENTRE_VEHICULOS +
                                       rand() % (int)(SEPARACION_PARA_PERSONAJE - SEPARACION_ENTRE_VEHICULOS + 1);

                if (nuevaPosicionX + ANCHO_AUTO <= tamVentana) {
                    vehiculos.push_back(new Colectivo(nuevaPosicionX, posY, direccion));
                } else {
                    break;
                }
            }
        } else {
            posX = tamVentana + ANCHO_COLECTIVO;

            vehiculos.push_back(new Colectivo(posX, posY, direccion));

            for (int i = 1; i < 7; i++) {
                float nuevaPosicionX = vehiculos.back()->getPosOriginalX() - SEPARACION_ENTRE_VEHICULOS -
                                       rand() % (int)(SEPARACION_PARA_PERSONAJE - SEPARACION_ENTRE_VEHICULOS + 1);

                if (nuevaPosicionX - ANCHO_AUTO >= 0.0) {
                    vehiculos.push_back(new Colectivo(nuevaPosicionX, posY, direccion));
                } else {
                    break;
                }
            }

        }
    }

}

void Trafico::move(const Vector2u& tamVentana)
{
    for (auto& vehiculo : vehiculos) {
        vehiculo->move(tamVentana);
    }
}

void Trafico::draw(RenderWindow& window) {
    for (auto& vehiculo : vehiculos) {
        vehiculo->draw(window);
    }
}

bool Trafico::checkCollision(Personaje* personaje, RenderWindow& window) {
    for (auto& vehiculo : vehiculos) {
        if (personaje->getShape().getGlobalBounds().intersects(vehiculo->getShape().getGlobalBounds())) {
            Derrota perdiste(window);
            perdiste.derrotado(window);
            return true;  // Colisión detectada
        }
    }
    return false;  // No hay colisión
}
