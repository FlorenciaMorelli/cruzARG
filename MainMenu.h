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
        Text comoJugar;
        Text salirDelJuego;

    public:
        MainMenu(RenderWindow& ventanaCruzARG);

        void mostrarMenu(RenderWindow& ventanaCruzARG);
};

#endif // MAINMENU_H
