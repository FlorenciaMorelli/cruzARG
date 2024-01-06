#include "Personaje.h"
#include <SFML/Graphics.hpp>

Personaje::Personaje(Vector2u tamanio)
{
    personaje.setSize(Vector2f(50.0f, 50.0f));
    //personaje.setOrigin(Vector2f(personaje.getSize().x / 2.0f, personaje.getSize().y / 2.0f));
    personaje.setPosition(Vector2f(tamanio.x / 2.0f, tamanio.y - personaje.getSize().y));
}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::draw(RenderWindow& window)
{
    window.draw(this->personaje);
}

void Personaje::move(Event evnt)
{
    if(Keyboard::Key::Up == evnt.key.code)
        personaje.move(0.0f, -50.0f);
    if(Keyboard::Key::Down == evnt.key.code)
        personaje.move(0.0f, 50.0f);
    if(Keyboard::Key::Left == evnt.key.code)
        personaje.move(-50.0f, 0.0f);
    if(Keyboard::Key::Right == evnt.key.code)
        personaje.move(50.0f, 0.0f);
}
