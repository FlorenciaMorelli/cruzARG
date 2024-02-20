#ifndef VICTORIA_H
#define VICTORIA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "seleccionOpciones.h"

using namespace sf;

class Victoria
{
    private:
        RenderWindow *ventanaVictoria;
        SoundBuffer buffer;
        Sound winSound;
        Texture backgroundT;
        Font fuenteTexto;
        Color *textColor;
        Sprite background;
        Text nuevaPartida;
        Text salirDelJuego;
        opciones opcionSeleccionada = IniciarPartida;


    public:
        Victoria(RenderWindow& ventanaCruzARG);

        void ganador(RenderWindow& ventanaCruzARG);
};

#endif // VICTORIA_H
