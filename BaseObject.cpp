#include "BaseObject.h"

#include <SFML/Graphics.hpp>

using namespace sf;

BaseObject::BaseObject()
{
    //ctor
}

void BaseObject::draw(RenderWindow& window)
{
    window.draw(shape);
}

void BaseObject::setPosicion(double posX, double posY)
{
    shape.setPosition(posX, posY);
}
