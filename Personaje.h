#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;

class Personaje : public BaseObject
{
    public:
        Personaje(Vector2u tamanioVentana);
        ~Personaje();

        void move(Event evnt, Vector2u tamanioVentana);
        void push(Event evnt);


};

#endif // PERSONAJE_H
