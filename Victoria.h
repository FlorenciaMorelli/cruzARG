#ifndef VICTORIA_H
#define VICTORIA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "seleccionOpciones.h"

using namespace sf;

class Victoria
{
    private:
        RenderWindow *ventanaVictoria;
        Font fuenteTitulo;
        Font fuenteTexto;
        Text tituloVictoria;
        Text nuevaPartida;
        Text salirDelJuego;
        opciones opcionSeleccionada = IniciarPartida;


    public:
        Victoria(RenderWindow& ventanaCruzARG);

        void ganador(RenderWindow& ventanaCruzARG);
};

#endif // VICTORIA_H
