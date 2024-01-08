#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Taxi.h"
#include "Auto.h"
#include "BarreraJersey.h"

using namespace sf;

class Juego
{
    private:
        RenderWindow *window;
        Personaje *personaje;
        Taxi *taxi;
        Taxi *taxi2;
        Taxi *taxi3;
        Taxi *taxi4;
        Taxi *taxi5;
        Taxi *taxi6;
        Taxi *taxi7;

        Auto *autito;
        Auto *autito2;
        Auto *autito3;
        Auto *autito4;
        Auto *autito5;
        Auto *autito6;

        BarreraJersey *barrera;
        BarreraJersey *barrera2;
        BarreraJersey *barrera3;
        BarreraJersey *barrera4;
        BarreraJersey *barrera5;
        BarreraJersey *barrera6;
        BarreraJersey *barrera7;
        BarreraJersey *barrera8;
        BarreraJersey *barrera9;
        BarreraJersey *barrera10;
        BarreraJersey *barrera11;
        BarreraJersey *barrera12;
        BarreraJersey *barrera13;
        BarreraJersey *barrera14;
        BarreraJersey *barrera15;
        BarreraJersey *barrera16;
        BarreraJersey *barrera17;
        BarreraJersey *barrera18;
        BarreraJersey *barrera19;
        BarreraJersey *barrera20;
        BarreraJersey *barrera21;
        BarreraJersey *barrera22;
        BarreraJersey *barrera23;
        BarreraJersey *barrera24;







    public:
        Juego();
        ~Juego();

        void loop();
};

#endif // JUEGO_H
