#include "Taxi.h"
#include <SFML/Graphics.hpp>

using namespace sf;


Taxi::Taxi(float posX, float posY)
{
    taxi.setSize(Vector2f(90.0f, 60.0f));
    taxi.setFillColor(Color::Yellow);
    taxi.setPosition(Vector2f(posX, posY));

    this->posOriginalX = posX;
    this->posOriginalY = posY;

}

Taxi::~Taxi()
{
    //dtor
}

void Taxi::draw(RenderWindow& window)
{
    window.draw(taxi);
}

void Taxi::move(Vector2u tamanioVentana)
{
    taxi.move(0.2f, 0.0f);

    if(taxi.getPosition().x > tamanioVentana.x) //Si el taxi está fuera de la ventana
    {
        taxi.setPosition(Vector2f(-taxi.getSize().x, posOriginalY)); //Reaparece en el x = 0, manteniendo la posición de y
    }
}
