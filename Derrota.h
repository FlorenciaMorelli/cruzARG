#ifndef DERROTA_H
#define DERROTA_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Derrota
{
    private:
        RenderWindow *ventanaDerrota;
        Font fuenteTitulo;
        Font fuenteTexto;
        Text tituloDerrota;
        Text volverAJugar;
        Text salirDelJuego;


    public:
        Derrota(RenderWindow& ventanaCruzARG);

        void derrotado(RenderWindow& ventanaCruzARG);
};

#endif // DERROTA_H
