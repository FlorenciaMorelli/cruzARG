#include "Taxi.h"

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;

Taxi::Taxi(float posX, float posY)
{
    shape.setSize(Vector2f(90.0f, 60.0f));
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
    shape.move(0.2f, 0.0f);

    if(shape.getPosition().x > tamanioVentana.x) //Si el taxi está fuera de la ventana
    {
        shape.setPosition(Vector2f(-shape.getSize().x, posOriginalY)); //Reaparece en el x = 0, manteniendo la posición de y
    }
}
