#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "seleccionOpciones.h"

using namespace sf;

class MainMenu
{
    private:
        RenderWindow *ventanaMenu;
        SoundBuffer bufferArrow;
        Sound arrowPressed;
        Texture backgroundT;
        Font fuenteTexto;
        Color *textColor;
        Sprite background;
        Text iniciarPartida;
        Text comoJugar;
        Text salirDelJuego;
        opciones opcionSeleccionada = IniciarPartida;

    public:
        MainMenu(RenderWindow& ventanaCruzARG);

        void mostrarMenu(RenderWindow& ventanaCruzARG);
};

#endif // MAINMENU_H
