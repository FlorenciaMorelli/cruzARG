#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tiles.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Trafico.h"
#include "BarreraJersey.h"

using namespace sf;

class Juego
{
    private:
    RenderWindow *ventanaCruzARG;

    public:
        Juego();
};

#endif // JUEGO_H
