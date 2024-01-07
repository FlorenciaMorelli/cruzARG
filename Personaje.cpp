#include "Personaje.h"
#include <SFML/Graphics.hpp>

using namespace sf;


Personaje::Personaje(Vector2u tamanio)
{
    shape.setSize(Vector2f(50.0f, 50.0f));
    //shape.setOrigin(Vector2f(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f));
    shape.setPosition(Vector2f(tamanio.x / 2.0f, tamanio.y - shape.getSize().y));
}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::move(Event evnt)
{
    if(Keyboard::Key::Up == evnt.key.code)
        shape.move(0.0f, -50.0f);
    if(Keyboard::Key::Down == evnt.key.code)
        shape.move(0.0f, 50.0f);
    if(Keyboard::Key::Left == evnt.key.code)
        shape.move(-50.0f, 0.0f);
    if(Keyboard::Key::Right == evnt.key.code)
        shape.move(50.0f, 0.0f);
}
