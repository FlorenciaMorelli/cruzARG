#ifndef DERROTA_H
#define DERROTA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "seleccionOpciones.h"

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
        opciones opcionSeleccionada = IniciarPartida;


    public:
        Derrota(RenderWindow& ventanaCruzARG);

        void derrotado(RenderWindow& ventanaCruzARG);
};

#endif // DERROTA_H
