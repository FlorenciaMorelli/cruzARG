#include "Personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.h"

using namespace sf;


Personaje::Personaje(Vector2u tamanioVentana)
{
    shape.setSize(Vector2f(ANCHO_PERSONAJE, ALTURA_PERSONAJE));
    this->shapeTexture.loadFromFile("./assets/messi.png");
    shape.setTexture(&shapeTexture);

    this->soundBuffer.loadFromFile("./assets/sounds/step.mp3");
    this->movingSound.setBuffer(this->soundBuffer);

    shape.setPosition(Vector2f(tamanioVentana.x / 2.0f, tamanioVentana.y));
    shape.setOrigin(ANCHO_PERSONAJE / 2.0f, ALTURA_PERSONAJE);
}

Personaje::~Personaje(){}

void Personaje::move(Event evnt, Vector2u tamanioVentana)
{

    if(Keyboard::Key::Up == evnt.key.code){
        this->movingSound.play();
        if(shape.getPosition().y - PERSONAJE_CANT_MOVIMIENTO > 0.0f)
        {
            shape.move(0.0f, -PERSONAJE_CANT_MOVIMIENTO);
        } else {
            shape.move(0.0f, 0.0f);
        }
    }
    if(Keyboard::Key::Down == evnt.key.code){
        this->movingSound.play();
        if(shape.getPosition().y - PERSONAJE_CANT_MOVIMIENTO < tamanioVentana.y)
        {
            shape.move(0.0f, PERSONAJE_CANT_MOVIMIENTO);
        } else {
            shape.move(0.0f, 0.0f);
        }
    }
    if(Keyboard::Key::Left == evnt.key.code){
        this->movingSound.play();
        if(shape.getPosition().x - PERSONAJE_CANT_MOVIMIENTO > 0.0f)
        {
            shape.move(-PERSONAJE_CANT_MOVIMIENTO, 0.0f);
        } else {
            shape.move(0.0f, 0.0f);
        }
    }
    if(Keyboard::Key::Right == evnt.key.code){
        this->movingSound.play();
        if(shape.getPosition().x + PERSONAJE_CANT_MOVIMIENTO < tamanioVentana.x)
        {
            shape.move(PERSONAJE_CANT_MOVIMIENTO, 0.0f);
        } else {
            shape.move(0.0f, 0.0f);
        }
    }
}

void Personaje::push(Event evnt)
{
    if(Keyboard::Key::Up == evnt.key.code)
        shape.move(0.0f, PERSONAJE_CANT_MOVIMIENTO);
    if(Keyboard::Key::Down == evnt.key.code)
        shape.move(0.0f, -PERSONAJE_CANT_MOVIMIENTO);
    if(Keyboard::Key::Left == evnt.key.code)
        shape.move(PERSONAJE_CANT_MOVIMIENTO, 0.0f);
    if(Keyboard::Key::Right == evnt.key.code)
        shape.move(-PERSONAJE_CANT_MOVIMIENTO, 0.0f);
}
