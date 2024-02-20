#ifndef DERROTA_H
#define DERROTA_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "seleccionOpciones.h"

using namespace sf;

class Derrota
{
    private:
        RenderWindow *ventanaDerrota;
        SoundBuffer buffer;
        Sound defeatSound;
        SoundBuffer bufferArrow;
        Sound arrowPressed;
        Texture backgroundT;
        Font fuenteTexto;
        Color *textColor;
        Sprite background;
        Text volverAJugar;
        Text salirDelJuego;
        opciones opcionSeleccionada = IniciarPartida;


    public:
        Derrota(RenderWindow& ventanaCruzARG);

        void derrotado(RenderWindow& ventanaCruzARG);
};

#endif // DERROTA_H
