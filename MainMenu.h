#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class MainMenu
{
    private:
        RenderWindow *ventanaMenu;
        Font fuenteTitulo;
        Font fuenteTexto;
        Text tituloJuego;
        Text iniciarPartida;
        Text salirDelJuego;

    public:
        MainMenu();

        void mostrarMenu();
};

#endif // MAINMENU_H