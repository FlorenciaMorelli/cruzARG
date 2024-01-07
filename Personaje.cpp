#include "Personaje.h"
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

using namespace sf;


Personaje::Personaje(Vector2u tamanio)
{
    shape.setSize(Vector2f(ANCHO_PERSONAJE, ALTURA_PERSONAJE));
    shape.setPosition(Vector2f(tamanio.x / 2.0f, tamanio.y - shape.getSize().y));
}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::move(Event evnt)
{
    if(Keyboard::Key::Up == evnt.key.code)
        shape.move(0.0f, -PERSONAJE_CANT_MOVIMIENTO);
    if(Keyboard::Key::Down == evnt.key.code)
        shape.move(0.0f, PERSONAJE_CANT_MOVIMIENTO);
    if(Keyboard::Key::Left == evnt.key.code)
        shape.move(-PERSONAJE_CANT_MOVIMIENTO, 0.0f);
    if(Keyboard::Key::Right == evnt.key.code)
        shape.move(PERSONAJE_CANT_MOVIMIENTO, 0.0f);
}
