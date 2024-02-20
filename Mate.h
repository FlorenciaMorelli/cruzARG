#ifndef MATE_H
#define MATE_H

#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "DEFINITIONS.h"

#include "Personaje.h"
#include "Victoria.h"

using namespace sf;


class Mate : public BaseObject
{
    public:
        Mate(Vector2u tamanioVentana);

        bool tomado(Personaje* personaje, RenderWindow& window);
};

#endif // MATE_H
