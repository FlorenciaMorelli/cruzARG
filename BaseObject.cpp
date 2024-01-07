#include "BaseObject.h"

#include <SFML/Graphics.hpp>

using namespace sf;

BaseObject::BaseObject()
{
    //ctor
}

BaseObject::~BaseObject()
{
    //dtor
}

void BaseObject::draw(RenderWindow& window)
{
    window.draw(shape);
}