#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Personaje.h"
#include "Taxi.h"
#include "Auto.h"
#include "BarreraJersey.h"
#include "Tiles.h"

using namespace sf;

class Juego
{
    private:
        float carriles, veredaCerrito1, veredaCerrito2, cerrito, cantero1, nueveJulioAutos1, newJersey1, nueveJulioColectivos1, metrobus, nueveJulioColectivos2, newJersey2, nueveJulioAutos2, cantero2, carlosPellegrini, veredaPellegrini1, veredaPellegrini2;
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
        std::vector<Tiles*> metrobusVector;
        std::vector<Tiles*> calleCerrito;
        std::vector<Tiles*> pellegriniVereda;
        std::vector<Tiles*> canteroVector1;
        std::vector<Tiles*> canteroVector2;





    public:
        Juego();
        ~Juego();

        void loop();
        void crearMetrobus(Vector2u tamanioVentana, float posY);
        void crearCerrito(Vector2u tamanioVentana, float posY, float posY2);
        void crearPellegrini(Vector2u tamanioVentana, float posY, float posY2);
        void crearCantero(std::vector<Tiles*>& vect, Vector2u tamanioVentana, float posY);

};

#endif // JUEGO_H
