#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tiles.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Trafico.h"
#include "BarreraJersey.h"

#include <SFML/Audio.hpp>

using namespace sf;

class Juego
{
    private:
    RenderWindow *ventanaCruzARG;
    Music backgroundMusic;

    public:
        Juego();
};

#endif // JUEGO_H
