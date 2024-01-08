#include "Auto.h"

#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "DEFINITIONS.h"

using namespace sf;

Auto::Auto(float posX, float posY)
{
    shape.setSize(Vector2f(100.0f, 40.0f));

    this->shapeTexture.loadFromFile("./assets/car.png");
    shape.setTexture(&shapeTexture);

    shape.setPosition(Vector2f(posX, posY));
    shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));

    this->posOriginalX = posX;
    this->posOriginalY = posY;
}

Auto::~Auto()
{
    //dtor
}

void Auto::move()
{
    shape.move(-0.2f, 0.0);
    if(shape.getPosition().x < 0) //Si el taxi está fuera de la ventana
    {
        shape.setPosition(Vector2f(posOriginalX, posOriginalY)); //Reaparece en el x = 0, manteniendo la posición de y
    }
}
