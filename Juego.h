#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Taxi.h"

using namespace sf;

class Juego
{
    private:
        RenderWindow *window;
        Personaje *personaje;
        Taxi *taxi;
        Taxi *taxi2;


    public:
        Juego();
        ~Juego();

        void loop();
};

#endif // JUEGO_H
