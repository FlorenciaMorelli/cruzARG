#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Taxi.h"
#include "Auto.h"
#include "BarreraJersey.h"
#include "Tiles.h"

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

        Tiles *asfalto;
        Tiles *asfalto2;
        Tiles *asfalto3;
        Tiles *asfalto4;
        Tiles *asfalto5;
        Tiles *asfalto6;
        Tiles *asfalto7;
        Tiles *asfalto8;
        Tiles *asfalto9;
        Tiles *asfalto10;
        Tiles *asfalto11;
        Tiles *asfalto12;
        Tiles *asfalto13;
        Tiles *asfalto14;
        Tiles *asfalto15;
        Tiles *asfalto16;
        Tiles *asfalto17;
        Tiles *asfalto18;
        Tiles *asfalto19;
        Tiles *asfalto20;
        Tiles *asfalto21;
        Tiles *asfalto22;
        Tiles *asfalto23;
        Tiles *asfalto24;
        Tiles *asfalto25;
        Tiles *asfalto26;
        Tiles *asfalto27;
        Tiles *asfalto28;
        Tiles *asfalto29;
        Tiles *asfalto30;
        Tiles *asfalto31;
        Tiles *asfalto32;
        Tiles *asfalto33;
        Tiles *asfalto34;
        Tiles *asfalto35;
        Tiles *asfalto36;
        Tiles *asfalto37;
        Tiles *asfalto38;
        Tiles *asfalto39;
        Tiles *asfalto40;
        Tiles *asfalto41;
        Tiles *asfalto42;
        Tiles *asfalto43;
        Tiles *asfalto44;
        Tiles *asfalto45;
        Tiles *asfalto46;
        Tiles *asfalto47;
        Tiles *asfalto48;



        Tiles *pellegrini;
        Tiles *pellegrini2;
        Tiles *pellegrini3;
        Tiles *pellegrini4;
        Tiles *pellegrini5;
        Tiles *pellegrini6;
        Tiles *pellegrini7;
        Tiles *pellegrini8;
        Tiles *pellegrini9;
        Tiles *pellegrini10;
        Tiles *pellegrini11;
        Tiles *pellegrini12;

        Tiles *cerrito1;
        Tiles *cerrito2;
        Tiles *cerrito3;
        Tiles *cerrito4;
        Tiles *cerrito5;
        Tiles *cerrito6;
        Tiles *cerrito7;
        Tiles *cerrito8;
        Tiles *cerrito9;
        Tiles *cerrito10;
        Tiles *cerrito11;
        Tiles *cerrito12;

        Tiles *metrobus1;
        Tiles *metrobus2;
        Tiles *metrobus3;
        Tiles *metrobus4;
        Tiles *metrobus5;
        Tiles *metrobus6;
        Tiles *metrobus7;
        Tiles *metrobus8;
        Tiles *metrobus9;
        Tiles *metrobus10;
        Tiles *metrobus11;
        Tiles *metrobus12;













    public:
        Juego();
        ~Juego();

        void loop();
};

#endif // JUEGO_H
