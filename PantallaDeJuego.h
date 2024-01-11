#ifndef PANTALLADEJUEGO_H
#define PANTALLADEJUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tiles.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Trafico.h"
#include "BarreraJersey.h"

using namespace sf;

class PantallaDeJuego
{
    private:
        RenderWindow *window;
        Personaje *personaje;
        Mapa *nueveDeJulio;

        Trafico* traficoCerrito;
        Trafico* traficoNueveJulioAutos1;
        Trafico* traficoNueveJulioColectivos1;
        Trafico* traficoNueveJulioColectivos2;
        Trafico* traficoNueveJulioAutos2;
        Trafico* traficoCarlosPellegrini;

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

    public:
        PantallaDeJuego();

        void loop();
};

#endif // PANTALLADEJUEGO_H
