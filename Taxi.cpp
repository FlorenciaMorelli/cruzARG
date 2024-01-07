#include "Taxi.h"

#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "DEFINITIONS.h"

using namespace sf;

Taxi::Taxi(float posX, float posY)
{
    shape.setSize(Vector2f(ANCHO_TAXI, ALTURA_TAXI));
    shape.setFillColor(Color::Yellow);
    shape.setPosition(Vector2f(posX, posY));

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
        shape.setPosition(Vector2f(-shape.getSize().x, posOriginalY)); //Reaparece en el x = 0, manteniendo la posición de y
    }
}
