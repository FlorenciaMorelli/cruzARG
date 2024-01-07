#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"

using namespace sf;

class Personaje : public BaseObject
{
    public:
        Personaje(Vector2u tamanio);
        ~Personaje();

        void move(Event evnt);


};

#endif // PERSONAJE_H
