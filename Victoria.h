#ifndef VICTORIA_H
#define VICTORIA_H

#include <iostream>
#include <SFML/Graphics.hpp>

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


    public:
        Victoria(RenderWindow& ventanaCruzARG);

        void ganador(RenderWindow& ventanaCruzARG);
};

#endif // VICTORIA_H
