#include "Taxi.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Vehiculo.h"
#include "DEFINITIONS.h"

using namespace sf;

Taxi::Taxi(float posX, float posY, bool direccion) : Vehiculo(posX, posY, direccion)
{
    shape.setSize(Vector2f(ANCHO_TAXI, ALTURA_TAXI));

    this->direccion = direccion;
    if(direccion){
        this->shapeTexture.loadFromFile("./assets/taxiTrue.png");
        shape.setTexture(&shapeTexture);
    } else {
        this->shapeTexture.loadFromFile("./assets/taxiFalse.png");
        shape.setTexture(&shapeTexture);
    }

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));

    this->posOriginalX = posX;
    this->posOriginalY = posY;

}

void Taxi::move(Vector2u tamanioVentana)
{
    if(direccion){
        shape.move(TAXI_VEL_MOVIMIENTO_X, TAXI_VEL_MOVIMIENTO_Y);
        if(shape.getPosition().x > tamanioVentana.x)
        {
            shape.setPosition(Vector2f(-ANCHO_TAXI, posOriginalY));
        }
    } else {
        shape.move(-TAXI_VEL_MOVIMIENTO_X, TAXI_VEL_MOVIMIENTO_Y);
        if(shape.getPosition().x < 0)
        {
            shape.setPosition(Vector2f(tamanioVentana.x + ANCHO_TAXI, posOriginalY));
        }
    }
}
