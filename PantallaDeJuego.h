#ifndef PANTALLADEJUEGO_H
#define PANTALLADEJUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tiles.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Trafico.h"
#include "BarreraJersey.h"
#include "Mate.h"

using namespace sf;

class PantallaDeJuego
{
    private:
        Personaje *personaje;
        Mapa *nueveDeJulio;
        Mate *matecito;

        Trafico* traficoCerrito;
        Trafico* traficoNueveJulioAutos1;
        BarreraJersey *barrera1;
        Trafico* traficoNueveJulioColectivos1;
        Trafico* traficoNueveJulioColectivos2;
        BarreraJersey *barrera2;
        Trafico* traficoNueveJulioAutos2;
        Trafico* traficoCarlosPellegrini;


    public:
        PantallaDeJuego(RenderWindow& ventanaCruzARG);

        void loop(RenderWindow& ventanaCruzARG);
};

#endif // PANTALLADEJUEGO_H
