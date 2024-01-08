#include "Taxi.h"

#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "DEFINITIONS.h"

using namespace sf;

Taxi::Taxi(float posX, float posY)
{
    shape.setSize(Vector2f(ANCHO_TAXI, ALTURA_TAXI));

    this->shapeTexture.loadFromFile("./assets/taxi.png");
    shape.setTexture(&shapeTexture);

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));

    this->posOriginalX = posX;
    this->posOriginalY = posY;

}

Taxi::~Taxi()
{
    //dtor
}

void Taxi::move(Vector2u tamanioVentana)
{
    shape.move(TAXI_VEL_MOVIMIENTO_X, TAXI_VEL_MOVIMIENTO_Y);

    if(shape.getPosition().x > tamanioVentana.x) //Si el taxi está fuera de la ventana
    {
        shape.setPosition(Vector2f(posOriginalX + ANCHO_TAXI, posOriginalY)); //Reaparece en el x = 0, manteniendo la posición de y
    }

    //tengo que resolver la latencia de cuanod sale el taxi 1 de la ventana y todavía está el taxi 2 en la ventana
}
